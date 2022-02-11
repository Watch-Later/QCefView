"use strict";(self.webpackChunkqcefviewdoc=self.webpackChunkqcefviewdoc||[]).push([[956],{3905:function(e,t,n){n.d(t,{Zo:function(){return p},kt:function(){return d}});var r=n(7294);function i(e,t,n){return t in e?Object.defineProperty(e,t,{value:n,enumerable:!0,configurable:!0,writable:!0}):e[t]=n,e}function o(e,t){var n=Object.keys(e);if(Object.getOwnPropertySymbols){var r=Object.getOwnPropertySymbols(e);t&&(r=r.filter((function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable}))),n.push.apply(n,r)}return n}function a(e){for(var t=1;t<arguments.length;t++){var n=null!=arguments[t]?arguments[t]:{};t%2?o(Object(n),!0).forEach((function(t){i(e,t,n[t])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(n)):o(Object(n)).forEach((function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(n,t))}))}return e}function l(e,t){if(null==e)return{};var n,r,i=function(e,t){if(null==e)return{};var n,r,i={},o=Object.keys(e);for(r=0;r<o.length;r++)n=o[r],t.indexOf(n)>=0||(i[n]=e[n]);return i}(e,t);if(Object.getOwnPropertySymbols){var o=Object.getOwnPropertySymbols(e);for(r=0;r<o.length;r++)n=o[r],t.indexOf(n)>=0||Object.prototype.propertyIsEnumerable.call(e,n)&&(i[n]=e[n])}return i}var c=r.createContext({}),s=function(e){var t=r.useContext(c),n=t;return e&&(n="function"==typeof e?e(t):a(a({},t),e)),n},p=function(e){var t=s(e.components);return r.createElement(c.Provider,{value:t},e.children)},u={inlineCode:"code",wrapper:function(e){var t=e.children;return r.createElement(r.Fragment,{},t)}},f=r.forwardRef((function(e,t){var n=e.components,i=e.mdxType,o=e.originalType,c=e.parentName,p=l(e,["components","mdxType","originalType","parentName"]),f=s(n),d=i,h=f["".concat(c,".").concat(d)]||f[d]||u[d]||o;return n?r.createElement(h,a(a({ref:t},p),{},{components:n})):r.createElement(h,a({ref:t},p))}));function d(e,t){var n=arguments,i=t&&t.mdxType;if("string"==typeof e||i){var o=n.length,a=new Array(o);a[0]=f;var l={};for(var c in t)hasOwnProperty.call(t,c)&&(l[c]=t[c]);l.originalType=e,l.mdxType="string"==typeof e?e:i,a[1]=l;for(var s=2;s<o;s++)a[s]=n[s];return r.createElement.apply(null,a)}return r.createElement.apply(null,n)}f.displayName="MDXCreateElement"},9686:function(e,t,n){n.r(t),n.d(t,{frontMatter:function(){return l},contentTitle:function(){return c},metadata:function(){return s},toc:function(){return p},default:function(){return f}});var r=n(7462),i=n(3366),o=(n(7294),n(3905)),a=["components"],l={},c="Getting Started",s={unversionedId:"intros/index",id:"intros/index",title:"Getting Started",description:"What's QCefView?",source:"@site/docs/intros/index.md",sourceDirName:"intros",slug:"/intros/",permalink:"/QCefView/docs/intros/",editUrl:"https://github.com/CefView/QCefViewDoc/tree/master/docs/intros/index.md",tags:[],version:"current",frontMatter:{},sidebar:"default",next:{title:"Building Instruction",permalink:"/QCefView/docs/intros/buiding"}},p=[{value:"What&#39;s QCefView?",id:"whats-qcefview",children:[],level:2},{value:"Why use QCefView rather than Electron?",id:"why-use-qcefview-rather-than-electron",children:[],level:2},{value:"What kinds of application is QCefView good at?",id:"what-kinds-of-application-is-qcefview-good-at",children:[],level:2},{value:"Do not want Qt, any better choice?",id:"do-not-want-qt-any-better-choice",children:[],level:2}],u={toc:p};function f(e){var t=e.components,n=(0,i.Z)(e,a);return(0,o.kt)("wrapper",(0,r.Z)({},u,n,{components:t,mdxType:"MDXLayout"}),(0,o.kt)("h1",{id:"getting-started"},"Getting Started"),(0,o.kt)("h2",{id:"whats-qcefview"},"What's QCefView?"),(0,o.kt)("p",null,"QCefView is a Qt Widget integrated with ",(0,o.kt)("a",{parentName:"p",href:"https://bitbucket.org/chromiumembedded"},"Chromium Embedded Framework"),". With QCefView you could build your application to leverage the powerful capabilities of CEF easily."),(0,o.kt)("ul",null,(0,o.kt)("li",{parentName:"ul"},"Write the application with familiar Qt forms, signals and slots"),(0,o.kt)("li",{parentName:"ul"},"straightforward interoperability between Web(Javascript) and Native(C++)")),(0,o.kt)("h2",{id:"why-use-qcefview-rather-than-electron"},"Why use QCefView rather than Electron?"),(0,o.kt)("p",null,"QCefView is totally different thing with Electron. "),(0,o.kt)("ul",null,(0,o.kt)("li",{parentName:"ul"},"QCefView is just a component of Qt framework for UI development while Electron is a comprehensive framework for application development"),(0,o.kt)("li",{parentName:"ul"},"QCefView is designed for Native language developers while Electron is more friendly to Frontend developers "),(0,o.kt)("li",{parentName:"ul"},"QCefView takes C++ as the primary development language while Electron is based on Javascript"),(0,o.kt)("li",{parentName:"ul"},"QCefView provides straightforward interoperability between Web and Native while Electron needs to write plugins")),(0,o.kt)("h2",{id:"what-kinds-of-application-is-qcefview-good-at"},"What kinds of application is QCefView good at?"),(0,o.kt)("p",null,"QCefView is good choice if you want to write the UI with Web Frontend technology and the core functions with native languages. "),(0,o.kt)("p",null,"For example:"),(0,o.kt)("ul",null,(0,o.kt)("li",{parentName:"ul"},"Movie/Music Player"),(0,o.kt)("li",{parentName:"ul"},"Game platforms"),(0,o.kt)("li",{parentName:"ul"},"Utility applications"),(0,o.kt)("li",{parentName:"ul"},"etc.")),(0,o.kt)("p",null,"In the above scenarios, the applications are almost all context based. They need to display some lists, tables or complex pages with cool effect, for these purpose, web frontend technology is really good solution. Just write the UI as WebApp, host it with QCefView (QCefView is like a WebApp container), and keep your hard-core business logic as native developed component, then combine them with the interoperability provide by QCefView."),(0,o.kt)("p",null,(0,o.kt)("strong",{parentName:"p"},"If you aimed to develop a web browser application, QCefView is not the choice for you. Because QCefView was designed to be an UI component not the browser, thus QCefView disabled some features which are required by a browser. For this purpose, you may prefer the original CEF library.")),(0,o.kt)("h2",{id:"do-not-want-qt-any-better-choice"},"Do not want Qt, any better choice?"),(0,o.kt)("p",null,"If you don't like Qt you can build the customized CEF view with the original CEF library, for example you can integrate CEF with Cocoa framework like this project ",(0,o.kt)("a",{parentName:"p",href:"https://github.com/CefView/CocoaCefView"},"CocoaCefView"),"."))}f.isMDXComponent=!0}}]);