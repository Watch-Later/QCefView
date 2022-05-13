﻿#include <QCefView.h>

#pragma region qt_headers
#include <QPainter>
#include <QPoint>
#include <QResizeEvent>
#include <QVBoxLayout>
#include <QtDebug>
#pragma endregion qt_headers

#include <QCefContext.h>

#include "details/QCefEventPrivate.h"
#include "details/QCefViewPrivate.h"

QCefView::QCefView(const QString url, const QCefSetting* setting, QWidget* parent /*= 0*/)
  : QWidget(parent)
  , d_ptr(new QCefViewPrivate(QCefContext::instance()->d_func(), this, url, setting))
{
#if defined(CEF_USE_OSR)
  setBackgroundRole(QPalette::Window);
  setAttribute(Qt::WA_OpaquePaintEvent);
#endif

  setMouseTracking(true);
  setFocusPolicy(Qt::WheelFocus);
}

QCefView::QCefView(QWidget* parent /*= 0*/)
  : QCefView("about:blank", nullptr, parent)
{}

QCefView::~QCefView()
{
  qDebug() << this << "is being destructed";
}

int
QCefView::browserId()
{
  Q_D(QCefView);

  return d->browserId();
}

void
QCefView::navigateToString(const QString& content)
{
  Q_D(QCefView);

  d->navigateToString(content);
}

void
QCefView::navigateToUrl(const QString& url)
{
  Q_D(QCefView);

  d->navigateToUrl(url);
}

bool
QCefView::browserCanGoBack()
{
  Q_D(QCefView);

  return d->browserCanGoBack();
}

bool
QCefView::browserCanGoForward()
{
  Q_D(QCefView);

  return d->browserCanGoForward();
}

void
QCefView::browserGoBack()
{
  Q_D(QCefView);

  d->browserGoBack();
}

void
QCefView::browserGoForward()
{
  Q_D(QCefView);

  d->browserGoForward();
}

bool
QCefView::browserIsLoading()
{
  Q_D(QCefView);

  return d->browserIsLoading();
}

void
QCefView::browserReload()
{
  Q_D(QCefView);

  d->browserReload();
}

void
QCefView::browserStopLoad()
{
  Q_D(QCefView);

  d->browserStopLoad();
}

bool
QCefView::triggerEvent(const QCefEvent& event)
{
  Q_D(QCefView);

  return d->triggerEvent(event.eventName(), event.d_func()->args, CefViewBrowserClient::MAIN_FRAME);
}

bool
QCefView::triggerEvent(const QCefEvent& event, int64_t frameId)
{
  Q_D(QCefView);

  return d->triggerEvent(event.eventName(), event.d_func()->args, frameId);
}

bool
QCefView::broadcastEvent(const QCefEvent& event)
{
  Q_D(QCefView);

  return d->triggerEvent(event.eventName(), event.d_func()->args, CefViewBrowserClient::ALL_FRAMES);
}

bool
QCefView::responseQCefQuery(const QCefQuery& query)
{
  Q_D(QCefView);

  return d->responseQCefQuery(query);
}

bool
QCefView::executeJavascript(int64_t frameId, const QString& code, const QString& url)
{
  Q_D(QCefView);

  return d->executeJavascript(frameId, code, url);
}

bool
QCefView::executeJavascriptWithResult(int64_t frameId, const QString& code, const QString& url, int64_t context)
{
  Q_D(QCefView);

  return d->executeJavascriptWithResult(frameId, code, url, context);
}

bool
QCefView::setPreference(const QString& name, const QVariant& value, const QString& error)
{
  Q_D(QCefView);

  return d->setPreference(name, value, error);
}

bool
QCefView::onBeforePopup(qint64 frameId,
                        const QString& targetUrl,
                        const QString& targetFrameName,
                        QCefView::WindowOpenDisposition targetDisposition,
                        QCefSetting& settings,
                        bool& DisableJavascriptAccess)
{
  // return false to allow the popup browser
  return false;
}

void
QCefView::onPopupCreated(QWindow* wnd)
{}

QVariant
QCefView::inputMethodQuery(Qt::InputMethodQuery query) const
{
#if defined(CEF_USE_OSR)
  Q_D(const QCefView);
  auto r = d->onViewInputMethodQuery(query);
  if (r.isValid())
    return r;
#endif

  return QWidget::inputMethodQuery(query);
}

void
QCefView::paintEvent(QPaintEvent* event)
{
  Q_D(QCefView);

#if defined(CEF_USE_OSR)
  QPainter painter(this);

  // paint background
  painter.fillRect(rect(), palette().color(backgroundRole()));

  // get current scale factor
  qreal scaleFactor = devicePixelRatio();
  float x, y, w, h = 0;

  // perform the painting
  {
    QMutexLocker lock(&(d->osr.qCefFramePaintLock_));

    // transform pop-up rect to widget coordinate system
    x = d->osr.qPopupRect_.x() / scaleFactor;
    y = d->osr.qPopupRect_.y() / scaleFactor;
    w = d->osr.qPopupRect_.width() / scaleFactor;
    h = d->osr.qPopupRect_.height() / scaleFactor;
    QRectF popupRect{ x, y, (w), (h) };

    // re-paint dirty regions of main view
    for (auto& dirtyRect : event->region()) {
      x = dirtyRect.x() * scaleFactor;
      y = dirtyRect.y() * scaleFactor;
      w = dirtyRect.width() * scaleFactor;
      h = dirtyRect.height() * scaleFactor;
      painter.drawImage(dirtyRect,             //
                        d->osr.qCefViewFrame_, //
                        QRectF{ x, y, w, h }   //
      );

      // re-paint only dirty regions of pop-up view
      if (d->osr.showPopup_) {
        QRectF destRect = popupRect.intersected(dirtyRect);
        if (!destRect.isEmpty()) {
          x = destRect.x() * scaleFactor - d->osr.qPopupRect_.x();
          y = destRect.y() * scaleFactor - d->osr.qPopupRect_.y();
          w = destRect.width() * scaleFactor;
          h = destRect.height() * scaleFactor;
          painter.drawImage(destRect,               //
                            d->osr.qCefPopupFrame_, //
                            QRectF{ x, y, w, h }    //
          );
        }
      }
    }

    // re-paint entire pop-up view
    // if (d->osr.showPopup_) {
    //  painter.drawImage(popupRect,             //
    //                    d->osr.qCefPopupFrame_ //
    //  );
    //}
  }
#endif

  QWidget::paintEvent(event);
}

void
QCefView::inputMethodEvent(QInputMethodEvent* event)
{
  Q_D(QCefView);
  d->onViewInputMethodEvent(event);
}

void
QCefView::showEvent(QShowEvent* event)
{
  Q_D(QCefView);
  d->onViewVisibilityChanged(true);
  QWidget::showEvent(event);
}

void
QCefView::hideEvent(QHideEvent* event)
{
  Q_D(QCefView);
  d->onViewVisibilityChanged(false);
  QWidget::hideEvent(event);
}

void
QCefView::focusInEvent(QFocusEvent* event)
{
  Q_D(QCefView);
  d->onViewFocusChanged(true);
  QWidget::focusInEvent(event);
}

void
QCefView::focusOutEvent(QFocusEvent* event)
{
  Q_D(QCefView);
  d->onViewFocusChanged(false);
  QWidget::focusOutEvent(event);
}

void
QCefView::resizeEvent(QResizeEvent* event)
{
  Q_D(QCefView);
  d->onViewSizeChanged(event->size(), event->oldSize());
  QWidget::resizeEvent(event);
}

void
QCefView::keyPressEvent(QKeyEvent* event)
{
  Q_D(QCefView);
  d->onViewKeyEvent(event);
  QWidget::keyPressEvent(event);
}

void
QCefView::keyReleaseEvent(QKeyEvent* event)
{
  Q_D(QCefView);
  d->onViewKeyEvent(event);
  QWidget::keyReleaseEvent(event);
}

void
QCefView::mouseMoveEvent(QMouseEvent* event)
{
  Q_D(QCefView);
  d->onViewMouseEvent(event);
  QWidget::mouseMoveEvent(event);
}

void
QCefView::mousePressEvent(QMouseEvent* event)
{
  Q_D(QCefView);
  d->onViewMouseEvent(event);
  QWidget::mousePressEvent(event);
}

void
QCefView::mouseReleaseEvent(QMouseEvent* event)
{
  Q_D(QCefView);
  d->onViewMouseEvent(event);
  QWidget::mouseReleaseEvent(event);
}

void
QCefView::wheelEvent(QWheelEvent* event)
{
  Q_D(QCefView);
  d->onViewWheelEvent(event);
  QWidget::wheelEvent(event);
}
