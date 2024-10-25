"use strict";(self.webpackChunk_N_E=self.webpackChunk_N_E||[]).push([[2509],{28368:function(e,t,r){var n;r.d(t,{j:function(){return o}});let o=((n={}).Starter="starter",n.Reply="reply",n.Autocomplete="autocomplete",n)},7937:function(e,t,r){function n(e){return null!=e}r.d(t,{BB:function(){return u},He:function(){return d},OP:function(){return f},PO:function(){return l},WU:function(){return m},aS:function(){return c},lm:function(){return n},qo:function(){return i},r3:function(){return o},sw:function(){return p}});let o=(e,t)=>e.includes(t),i=function(e,t){let r=arguments.length>2&&void 0!==arguments[2]?arguments[2]:[];if(null==e)return r;let n=Array.isArray(e)?e:[e];return t?n.map(t):n},l=function(e){let t=arguments.length>1&&void 0!==arguments[1]?arguments[1]:[];return r=>i(r,e,t)},a=function(e){let t=arguments.length>1&&void 0!==arguments[1]?arguments[1]:void 0;return"object"!=typeof e||null==e||Array.isArray(e)?t:e},s=(e,t)=>{let r=a(e),n={};for(let e in t)n[e]=t[e](r?.[e]);return n},c=e=>t=>s(t,e),u=function(e){let t=arguments.length>1&&void 0!==arguments[1]?arguments[1]:"";return"object"==typeof e||null==e?t:String(e)},d=function(e){let t=arguments.length>1&&void 0!==arguments[1]?arguments[1]:0;if("object"==typeof e||null==e)return t;let r=Number(e);return isNaN(r)?t:r},p=function(e){let t=arguments.length>1&&void 0!==arguments[1]&&arguments[1];if("boolean"==typeof e)return e;if("number"==typeof e){if(0===e)return!1;if(1===e)return!0}if("string"==typeof e){let t=e.toLowerCase();if("false"===t)return!1;if("true"===t)return!0}return t},m=function(e,t){let r=arguments.length>2&&void 0!==arguments[2]?arguments[2]:t[0];return o(t,e)?e:r},f=e=>t=>void 0===t?void 0:e(t)},66587:function(e,t,r){r.d(t,{Z:function(){return c}});var n=r(98601),o=r(52088),i=r(19841),l=r(651);let a=["className"];function s(e,t){var r=Object.keys(e);if(Object.getOwnPropertySymbols){var n=Object.getOwnPropertySymbols(e);t&&(n=n.filter(function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable})),r.push.apply(r,n)}return r}function c(e){let{className:t}=e,r=(0,o.Z)(e,a);return(0,l.jsx)("textarea",function(e){for(var t=1;t<arguments.length;t++){var r=null!=arguments[t]?arguments[t]:{};t%2?s(Object(r),!0).forEach(function(t){(0,n.Z)(e,t,r[t])}):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(r)):s(Object(r)).forEach(function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(r,t))})}return e}({className:(0,i.default)("form-textarea w-full rounded-lg border border-token-border-light bg-token-main-surface-secondary text-sm text-token-text-primary focus:border-token-text-primary focus:shadow-none focus:outline-none focus:ring-token-text-primary",t)},r))}},17004:function(e,t,r){r.d(t,{E:function(){return i},P:function(){return o}});var n=r(92379);let o=(0,n.createContext)({isEmbeddedInFocusedView:!1});function i(){return(0,n.useContext)(o).isEmbeddedInFocusedView}},55357:function(e,t,r){r.d(t,{B:function(){return l},X:function(){return i}});var n=r(16757),o=r(7937);let i=e=>(0,o.r3)([n.OL.GizmoMagicCreate,n.OL.GizmoTest],e?.kind),l=e=>(0,o.r3)([n.OL.GizmoInteraction,n.OL.GizmoMagicCreate,n.OL.GizmoTest],e?.kind)},2319:function(e,t,r){r.d(t,{D:function(){return o},Q:function(){return i}});var n=r(92379);let o=n.createContext({mode:void 0,getGizmoId:void 0}),i=()=>(0,n.useContext)(o)},10083:function(e,t,r){r.d(t,{X:function(){return f},r:function(){return m}});var n=r(12128),o=r(10080),i=r(15913),l=r(19841),a=r(50820),s=r(33138),c=r(54097),u=r(83036),d=r(45334),p=r(651);function m(e){let{gizmo:t,hideOwner:r=!1,children:n,className:o,avatarClassName:i,showStarterPrompts:a=!1,disableStarterPrompts:s=!1}=e;return null==t?null:(0,p.jsx)(p.Fragment,{children:(0,p.jsxs)("div",{className:(0,l.default)("flex h-full flex-col items-center justify-center text-token-text-primary",o),children:[(0,p.jsx)(f,{gizmo:t,avatarClassName:i}),(0,p.jsx)(h,{gizmo:t,hideOwner:r,showStarterPrompts:a,disableStarterPrompts:s}),n]})})}function f(e){let{gizmo:t,avatarClassName:r}=e,i=!!(null!=t&&(0,d.S9)(t)&&t?.gizmo.tags?.includes(o.U9.FirstParty));return(0,p.jsx)("div",{className:"relative",children:(0,p.jsx)(n.Z,{isFirstParty:i||!t,src:null!=t&&(0,d.WQ)(t)?t.profilePictureUrl:t?.gizmo.display.profile_picture_url,className:(0,l.default)("mb-3 h-12 w-12",r)})})}function g(e){let{gizmo:t,disabled:r}=e,n=(0,c.O)(t),o=(0,a.f)(),l=(0,i.BL)();if(null==n||0===n.length)return null;let u=n.slice(0,l?2:4);return(0,p.jsx)(s.cS,{starterPrompts:u,onSelectStarterPrompt:o,disabled:r})}function h(e){let{gizmo:t,hideOwner:r,showStarterPrompts:n,disableStarterPrompts:o}=e,i=null!=t&&(0,d.WQ)(t)?t.name:t?.gizmo.display.name,l=null!=t&&(0,d.WQ)(t)?t.description:t?.gizmo.display.description;return(0,p.jsxs)("div",{className:"flex flex-col items-center gap-2",children:[(0,p.jsx)("div",{className:"text-center text-2xl font-semibold",children:i}),!r&&(0,p.jsx)("div",{className:"flex items-center gap-1 text-token-text-tertiary",children:(0,p.jsx)(p.Fragment,{children:t&&(0,d.WQ)(t)?(0,p.jsx)(u.Z,{gizmo:t}):(0,p.jsx)(u.Z,{gizmo:t,socials:t.gizmo.author.display_socials})})}),l&&(0,p.jsx)("div",{className:"max-w-md text-center text-sm font-normal text-token-text-primary",children:l}),n&&(0,p.jsx)(g,{gizmo:t,disabled:o})]})}},8643:function(e,t,r){r.d(t,{b:function(){return a},l:function(){return s}});var n=r(83271),o=r(92379),i=r(651);let l=(0,o.createContext)(null);function a(e){let{children:t}=e;return(0,i.jsx)(l.Provider,{value:{store:(0,o.useRef)((0,n.rd)()).current},children:t})}function s(){let e=(0,o.useContext)(l);if(!e)throw Error("usePromptTextareaContext must be used within a PromptTextareaProvider");return e}},83271:function(e,t,r){r.d(t,{Tk:function(){return u},cq:function(){return d},j9:function(){return p},rd:function(){return f}});var n,o,i,l=r(92379),a=r(68810),s=r(73177),c=r(95267);let u=((n={}).Header="Header",n.HeaderTop="HeaderTop",n.HeaderBottom="HeaderBottom",n),d=((o={}).Box="Box",o.ItemActions="ItemActions",o.PromptTextareaAction="PromptTextareaAction",o.BannerTermsDisclaimer="BannerTermsDisclaimer",o.BannerSignup="BannerSignup",o.BannersRateLimit="BannersRateLimit",o.BannerSidekickAnnouncement="BannerSidekickAnnouncement",o.BannerMemoryFull="BannerMemoryFull",o.ParagenControls="ParagenControls",o),p=((i={}).DallePromptControls="DallePromptControls",i),m={contentAreas:{[u.Header]:{dimensions:null,contentId:null},[u.HeaderTop]:{dimensions:null,contentId:null},[u.HeaderBottom]:{dimensions:null,contentId:null}},sharedProps:null};function f(){let e=(0,a.Ue)((0,s.XR)((0,c.n)(()=>m)));function t(t,r){e.setState(e=>{e.contentAreas[t].dimensions=r})}return{reset:()=>e.setState(m),useContentAreaId:t=>e(e=>e.contentAreas[t].contentId),useContentAreaApi:t=>({set:(0,l.useCallback)(r=>e.setState(e=>{e.contentAreas[t].contentId=r}),[t]),remove:(0,l.useCallback)(()=>{e.setState(e=>{e.contentAreas[t].contentId=null})},[t])}),useContentAreaDimensions:(t,r)=>e(e=>r(e.contentAreas[t].dimensions)),useContentAreaResizeObserver(e,r){(0,l.useEffect)(()=>{if(r.current){t(e,r.current.getBoundingClientRect());let n=new ResizeObserver(r=>{for(let n of r)t(e,n.contentRect)});return n.observe(r.current),()=>{n.disconnect(),t(e,null)}}},[r,e])},useIsHeaderContentAreaPopulated:()=>e(e=>!!e.contentAreas[u.HeaderTop].contentId||!!e.contentAreas[u.HeaderBottom].contentId),useSharedProps:t=>e(e=>t?t(e.sharedProps):e.sharedProps),useSetSharedProps:()=>(0,l.useCallback)(t=>{e.setState(e=>{e.sharedProps=t})},[])}}},50820:function(e,t,r){r.d(t,{f:function(){return c}});var n=r(92745),o=r(31438),i=r(90215),l=r(92379),a=r(8643),s=r(70879);function c(){let{store:e}=(0,a.l)(),t=e.useSharedProps();return(0,l.useCallback)(async(e,r,l)=>{if(!t)return;let{clientThreadId:a,currentLeafId:c,onCreateNewCompletion:u,onResetState:d,conversationMode:p}=t;o.vm.hideThreadHeader();let m=`${c}-nextPrompt`;await u({promptId:m,content:(0,i.bf)(e),eventMetadata:{eventSource:"mouse"},completionMetadata:{suggestions:r,conversationMode:p??n.iN.getConversationMode(a)},messageMetadata:{is_starter_prompt:!0,suggestion_type:e.type}});let f=n.tQ.getTree(a).getMessageId(m);d(),(0,i.wj)(e,l,a,f),(0,s.go)()},[t])}},33138:function(e,t,r){r.d(t,{cS:function(){return z},ch:function(){return C},pF:function(){return M}});var n=r(98601),o=r(52088),i=r(50820),l=r(79946),a=r(25905),s=r(67437),c=r(54097),u=r(35367),d=r(9026),p=r(92745),m=r(86025),f=r(15913),g=r(90215),h=r(45120),x=r(19841),b=r(21389),y=r(88600),v=r(38482),j=r.n(v),w=r(92379),_=r(75325),S=r(25162),P=r(651);let O=["promptStarters","onSelectStarterPrompt","isSendBlocked","clientThreadId","isTwoLine"];function k(e,t){var r=Object.keys(e);if(Object.getOwnPropertySymbols){var n=Object.getOwnPropertySymbols(e);t&&(n=n.filter(function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable})),r.push.apply(r,n)}return r}function A(e){for(var t=1;t<arguments.length;t++){var r=null!=arguments[t]?arguments[t]:{};t%2?k(Object(r),!0).forEach(function(t){(0,n.Z)(e,t,r[t])}):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(r)):k(Object(r)).forEach(function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(r,t))})}return e}let N=j()(()=>Promise.all([r.e(8682),r.e(2244)]).then(r.bind(r,23123)).then(e=>e.CaNewThreadSplash).catch(()=>()=>null),{loadableGenerated:{webpack:()=>[23123]}});function C(e){let{clientThreadId:t}=e,{isUnauthenticated:r}=(0,m.u)(),n=!r,o=(0,p.Zz)(t),l=(0,p.Kt)(t),a=(0,d.ep)(),g=(0,f.BL)(),x=(0,i.f)(),y=(0,s.Bv)(t),v=(0,u.Y)(y),{promptStarters:j,isSuccess:w,isError:_}=(0,c.P)(o&&!l,t,g?2:4),O=j&&j?.length>0,k=w&&O&&n&&!v,{layer:A}=(0,h.AH)("4031588851"),C=A.get("is_two_line",!1);return(0,P.jsx)(P.Fragment,{children:(0,P.jsx)(b.M,{children:(_||w)&&(0,P.jsxs)(P.Fragment,{children:[(0,P.jsx)(S.nI,{className:`h-12 w-12 ${n?"":"max-sm:hidden"}`}),k&&(0,P.jsx)(D,{initial:{opacity:0},animate:{opacity:1},transition:{duration:.3},promptStarters:j,onSelectStarterPrompt:x,isSendBlocked:a,clientThreadId:t,isTwoLine:C}),!O&&n&&!v&&(0,P.jsx)(E,{}),v?(0,P.jsx)(N,{}):null,_&&n&&(0,P.jsx)(E,{})]})})})}function E(){return(0,P.jsx)("div",{className:"mt-7 text-3xl",children:(0,P.jsx)(_.Z,{id:"24tuqq",defaultMessage:"Hi, how can I help?"})})}function D(e){let{promptStarters:t,onSelectStarterPrompt:r,isSendBlocked:n,clientThreadId:i,isTwoLine:l}=e,s=(0,o.Z)(e,O);return(0,w.useEffect)(()=>{(0,g.SB)(t,i)},[i]),(0,P.jsx)(P.Fragment,{children:l?(0,P.jsx)(y.E.div,A(A({},s),{},{className:"absolute bottom-6 w-full px-4",children:(0,P.jsx)(a.Nf,{children:(0,P.jsx)(M,{starterPrompts:t,onSelectStarterPrompt:r,disabled:n})})})):(0,P.jsx)(y.E.div,A(A({},s),{},{children:(0,P.jsx)(z,{starterPrompts:t,onSelectStarterPrompt:r,disabled:n})}))})}let B=/\s/;function z(e){let{starterPrompts:t,onSelectStarterPrompt:r,disabled:n}=e,o=t.map((e,o)=>{let i=e.oneliner??e.title;""===i&&(i=e.body);let a=B.test(i);return(0,P.jsxs)("button",{className:"relative flex w-40 flex-col gap-2 rounded-2xl border border-token-border-light px-3 pb-4 pt-3 text-start align-top text-[15px] shadow-xxs transition enabled:hover:bg-token-main-surface-secondary disabled:cursor-not-allowed",disabled:n,onClick:()=>r(e,t,o),children:[(0,P.jsx)(l.ey,{starterPrompt:e}),(0,P.jsx)("div",{className:(0,x.default)("line-clamp-3 max-w-full text-balance text-gray-600 dark:text-gray-500",a?"break-word":"break-all"),children:i})]},e.id??o)});if(o.length>2){let e=Math.floor(o.length/2);o=[o.slice(0,e),o.slice(e)].map((e,t)=>(0,P.jsx)("div",{className:"flex max-w-3xl flex-wrap items-stretch justify-center gap-4",children:e},t))}return(0,P.jsx)("div",{className:"mx-3 mt-12 flex max-w-3xl flex-wrap items-stretch justify-center gap-4",children:o})}function M(e){let{starterPrompts:t,onSelectStarterPrompt:r,disabled:n}=e,o=t.map((e,o)=>(0,P.jsx)("button",{className:"relative whitespace-nowrap rounded-2xl border border-token-border-light px-4 py-2 text-start align-top text-[15px] shadow-xxs transition enabled:hover:bg-token-main-surface-secondary disabled:cursor-not-allowed",disabled:n,onClick:()=>r(e,t,o),children:(0,P.jsxs)("div",{className:"flex flex-col overflow-hidden",children:[e.title&&(0,P.jsx)("div",{className:"truncate font-semibold",children:e.title}),(0,P.jsx)("div",{className:(0,x.default)("truncate font-normal",e.title?"opacity-50":""),children:e.body})]})},e.id??o)),i=Math.floor(o.length/2);return o=[o.slice(0,i),o.slice(i)].map((e,t)=>(0,P.jsx)("div",{className:"flex flex-col gap-2",children:e},t)),(0,P.jsx)("div",{className:"grid w-full grid-flow-row grid-cols-[repeat(auto-fit,minmax(250px,1fr))] gap-2",children:o})}},25905:function(e,t,r){r.d(t,{Nf:function(){return u},_4:function(){return d},nI:function(){return c}});var n=r(92745),o=r(31438),i=r(19841),l=r(17004),a=r(68745),s=r(651);function c(e){let{clientThreadId:t,showInlineEmbeddedDisplay:r,isStaticSharedThread:l,children:c,withVerticalPadding:u,withHorizontalPadding:d}=e,p=(0,a.L)(),m=(0,o.tN)(e=>e.isDesktopNavCollapsed),f=(0,o.tN)(e=>e.activeStageSidebar),g=d&&!l&&!p,h=d&&p&&!m,x=m&&d&&p,b=d&&(!x||!l||f)&&p,y=(0,n.ot)(t);return(0,s.jsx)("div",{className:(0,i.default)("text-base",u&&"py-[18px]",d&&!p&&"px-3 md:px-4",r&&!l?"ml-5":"m-auto",g&&"w-full md:px-5 lg:px-1 xl:px-5",h&&"md:px-5",b&&`w-full px-3 ${y||f?"":"lg:px-0"}`,x&&"md:px-0"),children:c})}function u(e){let{children:t}=e,r=(0,l.E)(),n=(0,o.tN)(e=>e.isDesktopNavCollapsed);return(0,s.jsx)("div",{className:(0,i.default)("mx-auto flex flex-1 gap-4 text-base md:gap-5 lg:gap-6",n?"md:max-w-3xl":"md:max-w-3xl lg:max-w-[40rem] xl:max-w-[48rem]",r&&"-mx-4"),children:t})}function d(e){let{children:t}=e,r=(0,l.E)(),n=(0,o.tN)(e=>e.isDesktopNavCollapsed);return(0,s.jsx)("div",{className:(0,i.default)("mx-auto gap-4 text-base md:gap-5 lg:gap-6",n?"md:max-w-3xl":"md:max-w-3xl lg:max-w-[40rem] xl:max-w-[48rem]",r&&"-mx-4"),children:t})}},68745:function(e,t,r){r.d(t,{L:function(){return s},m:function(){return c}});var n=r(45120),o=r(92379),i=r(651);function l(e){let{children:t,composerBarSize:r,footerBarSize:n}=e,o=r?.width??null,l=r?.height??null,a=n?.height??null;return(0,i.jsx)("div",{className:"contents",style:{"--composer-bar_current-width":null!==o?`${o}px`:void 0,"--composer-bar_current-height":null!==l?`${l-2}px`:void 0,"--composer-bar_footer-current-height":null!==a?`${a}px`:void 0},children:t})}function a(){let{disabled:e=!1}=arguments.length>0&&void 0!==arguments[0]?arguments[0]:{},{0:t,1:r}=(0,o.useState)(null),n=(0,o.useRef)(null),i=(0,o.useRef)(null);return[t,(0,o.useCallback)(t=>{if(i.current&&(i.current.disconnect(),i.current=null),n.current=t,e||!t)return;let l=new ResizeObserver(e=>{if(!e.length)return;let{width:t,height:n}=function(e){let t,r;if(e.borderBoxSize){let n=Array.isArray(e.borderBoxSize)?e.borderBoxSize[0]:e.borderBoxSize;t=n.inlineSize,r=n.blockSize}else t=e.contentRect.width,r=e.contentRect.height;return{width:t,height:r}}(e[0]);(0,o.startTransition)(()=>{r(e=>e&&e.width===t&&e.height===n?e:{width:t,height:n})})});l.observe(t),i.current=l},[e])]}function s(){let{value:e}=(0,n.fW)("1487207580");return e}function c(e){let{isArchived:t,defaultWidth:r=640,defaultHeight:n=52}=e,i=s()&&!t,[c,u]=a({disabled:!i}),[d,p]=a({disabled:!i}),m=c?.width??r,f=c?.height??n,g=i?`url('data:image/svg+xml,%3Csvg%20xmlns%3D%22http%3A//www.w3.org/2000/svg%22%20width%3D%22${m}%22%20height%3D%22${f}%22%3E%3Crect%20width%3D%22${m}%22%20height%3D%22${f}%22%20rx%3D%2226%22%20ry%3D%2226%22%20fill%3D%22white%22/%3E%3C/svg%3E')`:void 0,h=i?l:o.Fragment;return{composerBarSize:c,composerSkeleton:g,footerBarSize:d,isClippedComposerBar:i,setComposerBarElement:u,setFooterBarElement:p,ThreadSizeWrapper:h}}},54097:function(e,t,r){r.d(t,{O:function(){return m},P:function(){return f}});var n=r(16757),o=r(28368),i=r(93951),l=r(92745),a=r(84760),s=r(2721),c=r(55357),u=r(2319),d=r(39004),p=r(45334);function m(e){return(p.WQ(e)?e.promptStarters:e.gizmo.display.prompt_starters)?.map(e=>({type:o.j.Starter,title:"",body:e,prompt:e}))}function f(e,t,r,p,f){let g=(0,i.hz)(),h=(0,l.WA)(t),x=(0,d.b9)(h?.kind===n.OL.GizmoInteraction?h.gizmo_id:void 0).data,{gizmoEditorData:b,mode:y}=(0,u.Q)(),v=(0,c.B)(h),j=(0,i.t)(),w=e&&!v&&(p||!j?.isEnterprisey()),{data:_,isLoading:S,isSuccess:P,isError:O}=(0,a.a)({queryKey:["promptStarters",t,r,f],queryFn:()=>s.Z.getSampledPromptStarter(r,f),enabled:w});return null==g?{promptStarters:[],isLoading:!0,isSuccess:!1}:"test"===y&&b?{promptStarters:m(b)??[],isLoading:!1,isSuccess:!0}:null!=x?{promptStarters:m(x),isLoading:!1,isSuccess:!0}:w?{promptStarters:_?.items.map(e=>({type:o.j.Starter,id:e.id,title:e.title,body:e.description,prompt:e.prompt,category:e.category,oneliner:e.oneliner,theme:e.theme,requires_file_upload:e.requires_file_upload}))??[],isLoading:S,isSuccess:P,isError:O}:{promptStarters:[],isLoading:!1,isSuccess:!0}}},35367:function(e,t,r){r.d(t,{Y:function(){return i}});var n=r(66234),o=r(92379);function i(e){let t=(0,n.Uq)(),{0:i,1:l}=(0,o.useState)(()=>()=>!1);return(0,o.useEffect)(()=>{t&&Promise.all([r.e(8682),r.e(2244)]).then(r.bind(r,23123)).then(e=>l(()=>e.isModelEligibleForCa)).catch()},[t]),t&&i(e)}},66234:function(e,t,r){r.d(t,{D7:function(){return u},HY:function(){return d},LA:function(){return g},Uq:function(){return p}});var n=r(98601),o=r(88667),i=r(18939),l=r.n(i),a=r(85302);function s(e,t){var r=Object.keys(e);if(Object.getOwnPropertySymbols){var n=Object.getOwnPropertySymbols(e);t&&(n=n.filter(function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable})),r.push.apply(r,n)}return r}function c(e){for(var t=1;t<arguments.length;t++){var r=null!=arguments[t]?arguments[t]:{};t%2?s(Object(r),!0).forEach(function(t){(0,n.Z)(e,t,r[t])}):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(r)):s(Object(r)).forEach(function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(r,t))})}return e}function u(e){let t=arguments.length>1&&void 0!==arguments[1]?arguments[1]:[],r=arguments.length>2&&void 0!==arguments[2]?arguments[2]:[],n=!(arguments.length>3)||void 0===arguments[3]||arguments[3],o=function(e){let t=arguments.length>1&&void 0!==arguments[1]?arguments[1]:[];if(0===t.length)return e;let r=t.filter(t=>t.end_ix<=e.length&&"tether_markdown"===t.citation_format_type&&t.metadata?.type==="webpage");for(let t=r.length-1;t>=0;t--){let n=r[t];if(n.metadata?.type!=="webpage")continue;let{start_ix:o,end_ix:i,metadata:l}=n,a=e.substring(o,i).replace(/\[(.*?)\]\((\d+)\)/g,`[$1](${l?.url})`);e=e.substring(0,o)+a+e.substring(i)}return e}(e,t),i=[...r.length>0?[]:function(e){let t=arguments.length>1&&void 0!==arguments[1]?arguments[1]:[];if(0===t.length)return[];let r=[],n=t.filter(t=>t.end_ix<=e.length&&"tether_markdown"!==t.citation_format_type),o=(0,a.Jx)(e);for(let e=n.length-1;e>=0;e--){let t;let l=n[e],{start_ix:a,end_ix:s,metadata:u,invalid_reason:d}=l;if(!u?.type)continue;let p=o.slice(a,s).join("");switch(u.type){case"webpage":var i;t=c(c({},u),{},{type:"webpage",title:u.title??"",snippet:u.text??null,pub_date:null==(i=u.pub_date)?null:new Date(i).getTime()/1e3,matched_text:p,start_idx:a,end_idx:s,alt:null});break;case"file":t=c(c({},u),{},{matched_text:p,start_idx:a,end_idx:s,alt:null})}d&&(t={type:"invalid",alt:d,start_idx:a,end_idx:s,matched_text:p,invalid:!0});let m=!1;if(r.length>0){let e=r[r.length-1];f(e)===f(t)&&0===o.slice(e.end_idx,l.start_ix).join("").trim().length&&(r[r.length-1].end_idx=l.end_ix,m=!0)}!m&&t&&r.push(t)}return r}(o,t),...r];return{text:o,contentReferences:l()(i.map(e=>"file"===e.type?g(n,e):e))}}function d(){let{config:e}=(0,o.xb)("1001765573"),t=(0,o.xb)("3168246095");return e.get("ca_enabled",!1)?t.config.get("gizmo_ids",[],m):[]}function p(){return(0,o.xb)("1001765573").config.get("ca_enabled",!1)}function m(e){return Array.isArray(e)&&e.every(e=>"string"==typeof e)}function f(e){switch(e.type){case"file":return e.id;case"webpage":return e.url;case"invalid":return e.alt}}function g(e,t){let r;if(!e)return t;let n=t.name.split("\xa4");if(3!==n.length)return t;let[o,i,l]=n,a=l,s=l.lastIndexOf(".");-1!==s&&(a=l.slice(0,s));let u="Google Drive";if("gdrive"===o)r=`https://drive.google.com/file/d/${i}/view`,u="Google Drive";else if("gdoc"===o)r=`https://docs.google.com/document/d/${i}`,u="Google Docs";else{if("notion"!==o)return t;r=`https://www.notion.so/openai/${i}`,u="Notion"}return c(c({},t),{},{type:"webpage",url:r,title:a,snippet:u,pub_date:null})}},90215:function(e,t,r){r.d(t,{Er:function(){return h},Gb:function(){return d},QO:function(){return u},SB:function(){return f},bf:function(){return c},uf:function(){return g},wj:function(){return m}});var n=r(28368),o=r(92745),i=r(99976),l=r(61619),a=r(52455),s=r(88667);let c=e=>{switch(e.type){case n.j.Reply:return e.text;case n.j.Starter:case n.j.Autocomplete:return e.prompt}},u=e=>e.type===n.j.Reply,d=e=>e.type===n.j.Starter,p=e=>e.type===n.j.Autocomplete,m=(e,t,r,o)=>{switch(s.m9.logEvent("chatgpt_prompt_use_suggestion",c(e),{index:`${t}`,type:e.type}),e.type){case n.j.Reply:i.A.logEvent(l.M.useSuggestedReply,{value:c(e),prompt_type:n.j.Reply,messageId:o});break;case n.j.Starter:i.A.logEvent(l.M.useStarterPrompt,{value:c(e),prompt_type:n.j.Starter,title:e.title,body:e.body,id:e.id,category:e.category,client_thread_id:r,messageId:o,index:t,theme:e.theme});break;case n.j.Autocomplete:i.A.logEvent(l.M.useAutocomplete,{value:c(e),prompt_type:n.j.Autocomplete,title:e.title,body:e.body,id:e.id,category:e.category,index:t,messageId:o,client_thread_id:r,theme:e.theme})}},f=(e,t)=>{let r=o.tQ.getThreadCurrentLeafId(t),c=o.tQ.getTree(t).getMessageId(r);if(s.m9.logEvent("chatgpt_prompt_show_suggestions",`count_${e.length}`,{type:e[0].type}),e.every(u))i.A.logEvent(l.M.showSuggestedReplies,{prompt_count:e.length,prompt_type:n.j.Reply,client_thread_id:t,suggestions:e.map(e=>e.text),message_id:c});else if(e.every(d)){let{isAdditional:r}=e[0];i.A.logEvent(r?l.M.moreStarterPromptsShown:l.M.showStarterPrompts,{prompt_count:e.length,prompt_type:n.j.Starter,titles:e.map(e=>e.title),bodies:e.map(e=>e.body),ids:e.map(e=>e.id),client_thread_id:t,message_id:c,themes:e.map(e=>e.theme??"")}),r&&i.A.logEvent(l.M.expandMoreStarterPrompts,{client_thread_id:t,message_id:c})}else e.every(p)?i.A.logEvent(l.M.showAutocompletePrompts,{prompt_count:e.length,prompt_type:n.j.Autocomplete,titles:e.map(e=>e.title),bodies:e.map(e=>e.body),ids:e.map(e=>e.id),client_thread_id:t,message_id:c,themes:e.map(e=>e.theme??"")}):a.U.addError("Unhandled suggestion type",{type:e[0].type})},g=e=>{let t=o.tQ.getThreadCurrentLeafId(e),r=o.tQ.getTree(e).getMessageId(t);i.A.logEvent(l.M.showExpandMoreStarterPromptsButton,{client_thread_id:e,message_id:r})},h=e=>{let t=o.tQ.getThreadCurrentLeafId(e),r=o.tQ.getTree(e).getMessageId(t);i.A.logEvent(l.M.expandMoreStarterPrompts,{client_thread_id:e,message_id:r})}}}]);
//# sourceMappingURL=2509-4686c83d439299e4.js.map