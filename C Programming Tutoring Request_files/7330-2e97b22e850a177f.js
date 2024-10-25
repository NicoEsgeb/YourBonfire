"use strict";(self.webpackChunk_N_E=self.webpackChunk_N_E||[]).push([[7330],{9033:function(e,t,n){n.d(t,{Kd:function(){return j},v_:function(){return m}});var r=n(59725),s=n(98095),i=n(11433),o=n(15913),l=n(38482),a=n.n(l),c=n(34977),u=n(44425),d=n(26925),p=n(97193),f=n(51837),g=n(651);let h=a()(()=>Promise.all([n.e(8682),n.e(6481)]).then(n.bind(n,9760)).then(e=>e.AvatarButtons),{ssr:!1,loadableGenerated:{webpack:()=>[9760]}}),x=s.Z.Item;function O(){let e=d.ne.useStore();return(0,o.e2)()?(0,g.jsx)(x,{onClick:()=>{e.setState({shouldShowAddToHomePopover:!0})},icon:(0,g.jsx)(i.IAe,{className:"icon-md-heavy text-token-text-primary"}),children:"Add to home screen"}):null}function j(e){let{className:t,iconSize:n,children:r}=e,o=(0,f.L)(),l=(0,c.useRouter)();return(0,g.jsxs)(s.Z.Root,{modal:!1,children:[(0,g.jsx)(b,{className:t,iconSize:n,children:r}),(0,g.jsx)(s.Z.Portal,{children:(0,g.jsxs)(s.Z.Content,{collisionPadding:10,children:[(0,g.jsx)(x,{onClick:()=>p.vm.toggleSettingsModalOpen(),icon:(0,g.jsx)(i.SWE,{className:"icon-md-heavy text-token-text-primary"}),children:"Settings"}),(0,g.jsx)(x,{onClick:()=>window.open(u._A,"_blank"),icon:(0,g.jsx)(i.Jmo,{className:"icon-md-heavy text-token-text-primary"}),children:"About SearchGPT"}),(0,g.jsx)(x,{onClick:()=>window.open("https://chatgpt.com","_blank"),icon:(0,g.jsx)(i.Pfi,{className:"icon-md-heavy text-token-text-primary"}),children:"Open ChatGPT"}),(0,g.jsx)(O,{}),(0,g.jsx)(s.Z.Separator,{}),(0,g.jsx)(x,{onClick:()=>l.push("/auth/logout",void 0,{shallow:!0}),icon:(0,g.jsx)(i.iz5,{className:"icon-md-heavy text-token-text-primary"}),children:"Log out"}),o&&(0,g.jsx)(h,{})]})})]})}function m(e){let{className:t,iconSize:n}=e,r=(0,c.useRouter)();return(0,g.jsxs)(s.Z.Root,{modal:!1,children:[(0,g.jsx)(b,{className:t,iconSize:n}),(0,g.jsx)(s.Z.Portal,{children:(0,g.jsx)(s.Z.Content,{collisionPadding:10,children:(0,g.jsx)(x,{onClick:()=>r.push("/auth/logout",void 0,{shallow:!0}),icon:(0,g.jsx)(i.iz5,{className:"icon-md-heavy text-token-text-primary"}),children:"Log out"})})})]})}function b(e){let{className:t,iconSize:n,children:i}=e;return(0,g.jsx)(s.Z.Trigger,{className:"group border-0 !bg-transparent p-0",children:(0,g.jsx)("div",{className:"rounded-full",children:i??(0,g.jsx)(r.zf,{iconSize:n,className:t})})})}},67330:function(e,t,n){n.d(t,{aE:function(){return u},bW:function(){return c},jj:function(){return a}});var r=n(52455),s=n(92379),i=n(64925),o=n(95204),l=n(651);function a(e){let{children:t}=e;return(0,l.jsx)("div",{className:"flex h-full w-full items-center justify-center",children:(0,l.jsxs)("div",{className:"flex flex-col items-center gap-1 text-sm font-semibold text-token-text-tertiary",children:[(0,l.jsx)(o.Z,{className:"icon-2xl"}),t]})})}function c(e){let{onClickRetry:t,children:n}=e;return(0,l.jsxs)(a,{children:[(0,l.jsxs)("div",{children:["Error."," ",(0,l.jsx)("button",{onClick:t,className:"inline font-semibold text-token-text-primary hover:opacity-70",children:"Try again?"})]}),n]})}function u(e){let{resetError:t,componentStack:n,error:o}=e;return(0,s.useEffect)(()=>{r.U.addError(o)},[o]),(0,l.jsxs)(c,{onClickRetry:t,children:[(0,l.jsx)("div",{className:"fixed left-2 top-2",children:(0,l.jsx)(i.WU,{})}),(0,l.jsx)("div",{className:"fixed right-2 top-2",children:(0,l.jsx)(i.z0,{})}),!1]})}},64925:function(e,t,n){n.d(t,{Au:function(){return W},rm:function(){return Q},WU:function(){return Z},z0:function(){return U}});var r=n(25162),s=n(19841),i=n(24098),o=n.n(i),l=n(92379),a=n(15478),c=n(9033),u=n(30853),d=n(91981),p=n(651);let f={[d.kQ.CONNECTING]:"Connecting",[d.kQ.OPEN]:"Open",[d.kQ.CLOSING]:"Closing",[d.kQ.CLOSED]:"Closed",[d.kQ.UNINSTANTIATED]:"Uninstantiated"};function g(e){let{readyState:t,className:n}=e,{0:r,1:i}=(0,l.useState)(!0);return((0,l.useEffect)(()=>{setTimeout(()=>{i(!0)},1e3)},[]),t!==d.kQ.OPEN&&r)?(0,p.jsx)("div",{className:(0,s.default)("flex items-center gap-2 p-3 text-sm",n),children:(0,p.jsx)(u.u,{label:f[t],sideOffset:0,side:"right",children:(0,p.jsx)("div",{className:(0,s.default)("h-2 w-2 rounded-full",(t===d.kQ.CLOSING||t===d.kQ.CONNECTING)&&"bg-yellow-500",(t===d.kQ.CLOSED||t===d.kQ.UNINSTANTIATED)&&"bg-red-500",r?"block":"hidden")})})}):null}var h=n(98601),x=n(71522),O=n(11433),j=n(87387),m=n(52088);let b=["label","labelSide","className","onClick","children"];function y(e,t){var n=Object.keys(e);if(Object.getOwnPropertySymbols){var r=Object.getOwnPropertySymbols(e);t&&(r=r.filter(function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable})),n.push.apply(n,r)}return n}function v(e){for(var t=1;t<arguments.length;t++){var n=null!=arguments[t]?arguments[t]:{};t%2?y(Object(n),!0).forEach(function(t){(0,h.Z)(e,t,n[t])}):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(n)):y(Object(n)).forEach(function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(n,t))})}return e}function N(e){let{label:t,labelSide:n="right",className:r,onClick:i,children:o}=e,l=(0,m.Z)(e,b);return(0,p.jsx)(u.E,{label:t,sideOffset:0,side:n,disabled:!t,children:(0,p.jsx)("button",v(v({onClick:i,className:(0,s.default)("flex items-center justify-center p-1.5 text-token-text-tertiary hover:text-token-text-primary",r)},l),{},{children:o}))})}var S=n(26925),k=n(97193),P=n(10798),w=n(65925),M=n.n(w),C=n(99661);function D(e,t){var n=Object.keys(e);if(Object.getOwnPropertySymbols){var r=Object.getOwnPropertySymbols(e);t&&(r=r.filter(function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable})),n.push.apply(n,r)}return n}function I(e){for(var t=1;t<arguments.length;t++){var n=null!=arguments[t]?arguments[t]:{};t%2?D(Object(n),!0).forEach(function(t){(0,h.Z)(e,t,n[t])}):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(n)):D(Object(n)).forEach(function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(n,t))})}return e}function E(e,t){return Object.keys(e).reduce((n,r)=>(M()(e[r],t[r])||(n[r]=t[r]),n),{})}function T(){let{setTheme:e,resolvedTheme:t}=(0,C.F)(),n=S.ne.useState(S.ne.selectAgentSettingsOverrides),[r]=(0,P.OR)(),i=E(j.sH,n),o=E(P.Ws,r),l=I(I({},i),o),a=Object.keys(l).length>0;return(0,p.jsxs)(p.Fragment,{children:[(0,p.jsx)(N,{"data-testid":"sonic-debug-button",label:"Debug (Internal)",onClick:()=>k.vm.toggleDebugModalOpen(),children:(0,p.jsx)(O.reV,{className:"icon-sm-heavy"})}),(0,p.jsx)(N,{label:"Theme (Internal)",onClick:()=>{e("dark"===t?"light":"dark")},children:(0,p.jsxs)(x.ZP,{children:["dark"===t&&(0,p.jsx)(O.NWY,{className:"icon-md-heavy"}),"light"===t&&(0,p.jsx)(O.kLh,{className:"icon-md-heavy"})]})}),(0,p.jsx)(N,{label:a?["Config (Internal) - Changes:",Object.keys(l).join(", ")].join("\n"):"Config (Internal)",onClick:()=>k.vm.toggleInternalSettingsModalOpen(),children:(0,p.jsx)(O.KAl,{className:(0,s.default)(a?"icon-lg-heavy":"icon-md-heavy",{"text-red-500":a})})})]})}var A=n(91111),_=n(51837);function Z(e){let{hideReadyState:t=!1,onResultsPage:n=!1,children:i}=e,{readyState:l,resetSearch:a}=(0,A.A)(),c=(0,_.L)();return(0,p.jsxs)("div",{className:(0,s.default)("hidden w-20 shrink-0 flex-col items-center justify-between border-r py-6 sm:flex",n?"relative border-token-border-light":"absolute bottom-0 left-0 top-0 border-transparent"),children:[(0,p.jsxs)(o(),{onClick:()=>a(),href:"/search",className:"text-token-text-primary hover:text-token-text-secondary",title:"Go to SearchGPT",children:[(0,p.jsx)(r.nI,{className:"h-8 w-8"}),c&&!t&&(0,p.jsx)(g,{readyState:l})]}),c&&(0,p.jsx)("div",{className:"flex flex-col items-center gap-2",children:(0,p.jsx)(T,{})}),(0,p.jsx)("div",{className:"absolute top-1/2 -translate-y-1/2",children:i})]})}function U(){return(0,p.jsx)("div",{className:"absolute right-5 top-5 hidden sm:block",children:(0,p.jsx)(c.Kd,{className:"h-8 w-8"})})}function W(){return(0,p.jsx)(z,{$side:"left",children:(0,p.jsx)(r.nI,{className:"h-8 w-8"})})}function Q(e){let{className:t}=e;return(0,p.jsx)(z,{$side:"right",className:`${t}`,children:(0,p.jsx)(c.v_,{className:"h-8 w-8"})})}let z=a.Z.div`absolute ${e=>"left"===e.$side?"left-5":"right-5"} bottom-5 top-5 z-10 w-10 flex-col justify-between items-center hidden sm:flex`},91111:function(e,t,n){n.d(t,{A:function(){return a},c:function(){return l}});var r=n(91530),s=n.n(r),i=n(92379),o=n(91981);let l=(0,i.createContext)({waitingForNewTurn:!1,sessionUser:null,userMetadata:{cf_connecting_ip:null,ip_city:null,time_zone:null,user_country:null,user_locale:null,user_region:null,user_region_code:null,latitude:null,longitude:null,locationAccuracy:null},submitFollowup:()=>Promise.resolve(),submitSearch:()=>Promise.resolve(),retrySearch:()=>Promise.resolve(),resetSearch:s(),prefetch:s(),readyState:o.kQ.UNINSTANTIATED}),a=()=>(0,i.useContext)(l)},44425:function(e,t,n){n.d(t,{_A:function(){return r}});let r="https://openai.com/index/searchgpt-prototype/"},97193:function(e,t,n){n.d(t,{W6:function(){return l},bM:function(){return a},vm:function(){return c}});var r=n(98601),s=n(68810);function i(e,t){var n=Object.keys(e);if(Object.getOwnPropertySymbols){var r=Object.getOwnPropertySymbols(e);t&&(r=r.filter(function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable})),n.push.apply(n,r)}return n}let o={isInternalSettingsModalOpen:!1,isSettingsModalOpen:!1,isDebugModalOpen:!1,isUsageNuxModalOpen:!1,isWelcomePageOpen:!1},l=(0,s.Ue)()(()=>(function(e){for(var t=1;t<arguments.length;t++){var n=null!=arguments[t]?arguments[t]:{};t%2?i(Object(n),!0).forEach(function(t){(0,r.Z)(e,t,n[t])}):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(n)):i(Object(n)).forEach(function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(n,t))})}return e})({},o)),a={isInternalSettingsModalOpen:e=>e.isInternalSettingsModalOpen,isSettingsModalOpen:e=>e.isSettingsModalOpen,isDebugModalOpen:e=>e.isDebugModalOpen,isUsageNuxModalOpen:e=>e.isUsageNuxModalOpen,isWelcomePageOpen:e=>e.isWelcomePageOpen,isModalOpen:e=>a.isInternalSettingsModalOpen(e)||a.isSettingsModalOpen(e)||a.isDebugModalOpen(e)||a.isUsageNuxModalOpen(e)||a.isWelcomePageOpen(e)},c={toggleInternalSettingsModalOpen(){l.setState(e=>({isInternalSettingsModalOpen:!e.isInternalSettingsModalOpen}))},setInternalSettingsModalOpen(e){l.setState({isInternalSettingsModalOpen:e})},toggleSettingsModalOpen(){l.setState(e=>({isSettingsModalOpen:!e.isSettingsModalOpen}))},setSettingsModalOpen(e){l.setState({isSettingsModalOpen:e})},toggleDebugModalOpen(){l.setState(e=>({isDebugModalOpen:!e.isDebugModalOpen}))},setDebugModalOpen(e){l.setState({isDebugModalOpen:e})},setUsageNuxModalOpen(e){l.setState({isUsageNuxModalOpen:e})},setWelcomePageOpen(e){l.setState({isWelcomePageOpen:e})}}},51837:function(e,t,n){n.d(t,{L:function(){return s}});var r=n(45120);function s(){return r.fW("2000076788")?.value}}}]);
//# sourceMappingURL=7330-2e97b22e850a177f.js.map