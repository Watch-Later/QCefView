﻿#pragma once

#pragma region std_headers
#include <atomic>
#include <memory>
#include <mutex>
#include <string>
#pragma endregion std_headers

#pragma region qt_headers
#include <QCoreApplication>
#include <QList>
#include <QObject>
#include <QTimer>
#pragma endregion qt_headers

#include <CefViewBrowserApp.h>
#include <CefViewBrowserClient.h>

#include "CCefAppDelegate.h"
#include "QCefConfigPrivate.h"

typedef struct FolderResourceMapping
{
  QString path;
  QString url;
  int priority;
} FolderResourceMapping;

typedef struct ArchiveResourceMapping
{
  QString path;
  QString url;
  QString password;
  int priority;
} ArchiveResourceMapping;

/// <summary>
///
/// </summary>
class QCefContextPrivate : public QObject
{
  Q_OBJECT

private:
  int argc_;
  char** argv_;

private:
  QTimer cefWorkerTimer_;
  QList<FolderResourceMapping> folderResourceMappingList_;
  QList<ArchiveResourceMapping> archiveResourceMappingList_;

private:
  CefRefPtr<CefViewBrowserApp> pApp_;
  CCefAppDelegate::RefPtr pAppDelegate_;

public:
  /// <summary>
  ///
  /// </summary>
  QCefContextPrivate(QCoreApplication* app, int argc, char** argv);

  /// <summary>
  ///
  /// </summary>
  ~QCefContextPrivate();

  /// <summary>
  ///
  /// </summary>
  /// <returns></returns>
  CefRefPtr<CefViewBrowserApp> getCefApp();

  /// <summary>
  ///
  /// </summary>
  /// <param name="config"></param>
  /// <returns></returns>
  bool initialize(const QCefConfig* config);

  /// <summary>
  /// Adds a url mapping item with local web resource directory
  /// </summary>
  /// <param name="path">The path to the local resource directory</param>
  /// <param name="url">The url to be mapped to</param>
  /// <param name="priority">The priority</param>
  void addLocalFolderResource(const QString& path, const QString& url, int priority = 0);
  const QList<FolderResourceMapping>& folderResourceMappingList();

  /// <summary>
  /// Adds a url mapping item with local archive (.zip) file which contains the web resource
  /// </summary>
  /// <param name="path">The path to the local archive file</param>
  /// <param name="url">The url to be mapped to</param>
  /// <param name="password">The password of the archive</param>
  /// <param name="priority">The priority</param>
  void addArchiveResource(const QString& path, const QString& url, const QString& password = "", int priority = 0);
  const QList<ArchiveResourceMapping>& archiveResourceMappingList();

  /// <summary>
  ///
  /// </summary>
  void uninitialize();

  /// <summary>
  ///
  /// </summary>
  /// <param name="delayMs"></param>
  void scheduleCefLoopWork(int64_t delayMs);

  /// <summary>
  ///
  /// </summary>
  /// <param name="name"></param>
  /// <param name="value"></param>
  /// <param name="domain"></param>
  /// <param name="url"></param>
  /// <returns></returns>

  bool addGlobalCookie(const std::string& name,
                       const std::string& value,
                       const std::string& domain,
                       const std::string& url)
  {
    CefCookie cookie;
    CefString(&cookie.name).FromString(name);
    CefString(&cookie.value).FromString(value);
    CefString(&cookie.domain).FromString(domain);
    return CefCookieManager::GetGlobalManager(nullptr)->SetCookie(CefString(url), cookie, nullptr);
  }

public slots:
  /// <summary>
  ///
  /// </summary>
  void onAboutToQuit();

  /// <summary>
  ///
  /// </summary>
  void performCefLoopWork();

protected:
  /// <summary>
  ///
  /// </summary>
  /// <param name="argc"></param>
  /// <param name="argv"></param>
  /// <param name="config"></param>
  /// <returns></returns>
  bool initializeCef(const QCefConfig* config);

  /// <summary>
  ///
  /// </summary>
  void uninitializeCef();
};
