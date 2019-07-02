const char HTML[] PROGMEM = R"=====(
<!DOCTYPE html><html lang="en"><head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1.0"><style type="text/css">body{height:100vh;margin:0;background-color:#191919}.container{height:100vh;width:100vw;display:flex;justify-content:center;padding:40px;box-sizing:border-box}.speaker{width:400px;height:400px}.speaker__shadow,.speaker__wave{transition:all .3s;transform-origin:left}.speaker.off .speaker__shadow--small,.speaker.off .speaker__wave--small{transform:translateX(-10px)}.speaker.off .speaker__shadow--medium,.speaker.off .speaker__wave--medium{transform:translateX(-10px) scale(.8)}.speaker.off .speaker__shadow--large,.speaker.off .speaker__wave--large{transform:translateX(-3px) scale(.6)}.speaker__circle{fill:#bbb}.speaker__shadow{opacity:.2}.speaker__cone{fill:#4f5d73}.speaker__wave{fill:none;stroke-width:3;stroke-linecap:round;stroke-miterlimit:10}.speaker__wave--small{stroke:#fff}.speaker__wave--medium{stroke:#e0e0d1}.speaker__wave--large{stroke:#e4dac7}
/*# sourceMappingURL=styles.34dc3162.css.map */</style><title></title></head><body> <div class="container"> <svg class="speaker off" viewBox="0 0 64 64"><circle class="speaker__circle" cx="32" cy="32" r="32"></circle><path class="speaker__shadow" d="M33.9 12.2c-.3-.1-.6-.2-.9-.2-.4 0-.9.1-1.2.4L17.3 24H12c-1.1 0-2 .9-2 2v16c0 1.1.9 2 2 2h5.3l14.5 11.6c.4.3.8.4 1.2.4.3 0 .6-.1.9-.2.7-.3 1.1-1 1.1-1.8V14c0-.8-.4-1.5-1.1-1.8z"></path><path class="speaker__cone" d="M31 40c0 1.1-.9 2-2 2H12c-1.1 0-2-.9-2-2V24c0-1.1.9-2 2-2h17c1.1 0 2 .9 2 2v16z"></path><path class="speaker__shadow speaker__shadow--small" d="M38 36.8c-.7.5-.8 1.4-.3 2.1.3.4.8.6 1.2.6.3 0 .6-.1.9-.3 1.7-1.2 2.7-3.2 2.7-5.3s-1-4-2.7-5.3c-.7-.5-1.6-.3-2.1.3-.5.7-.3 1.6.3 2.1.9.7 1.5 1.7 1.5 2.8s-.5 2.4-1.5 3z"></path><path class="speaker__wave speaker__wave--small" d="M38.9 36c1.3-.9 2.1-2.4 2.1-4s-.8-3.1-2.1-4"></path><path class="speaker__shadow speaker__shadow--medium" d="M38.5 43.2c-.8.2-1.3 1-1 1.8.2.7.8 1.1 1.4 1.1.1 0 .3 0 .4-.1 5.4-1.5 9.2-6.4 9.2-12s-3.8-10.6-9.2-12c-.8-.2-1.6.3-1.8 1-.2.8.3 1.6 1 1.8 4.1 1.1 7 4.9 7 9.2s-2.9 8-7 9.2z"></path><path class="speaker__wave speaker__wave--medium" d="M38.9 42.6C43.6 41.3 47 37.1 47 32s-3.4-9.3-8.1-10.6"></path><path class="speaker__shadow speaker__shadow--large" d="M39.2 15.8c-.8-.1-1.6.4-1.7 1.2-.1.8.4 1.6 1.2 1.7C46.1 20 51.5 26.4 51.5 34s-5.4 14-12.8 15.3c-.8.1-1.4.9-1.2 1.7.1.7.8 1.2 1.5 1.2h.3C48.1 50.7 54.5 43 54.5 34s-6.4-16.7-15.3-18.2z"></path><path class="speaker__wave speaker__wave--large" d="M38.9 48.7C46.9 47.3 53 40.4 53 32s-6.1-15.3-14.1-16.7"></path><path class="speaker__cone" d="M33 53c-.2 0-.4-.1-.6-.2l-15-12c-.3-.2-.4-.5-.4-.8V24c0-.3.1-.6.4-.8l15-12c.2-.1.4-.2.6-.2.1 0 .3 0 .4.1.3.2.6.5.6.9v40c0 .4-.2.7-.6.9-.1.1-.3.1-.4.1z"></path><path class="speaker__cone" d="M33 12v40L18 40V24l15-12m0-2c-.4 0-.9.1-1.2.4l-15 12c-.5.4-.8 1-.8 1.6v16c0 .6.3 1.2.8 1.6l15 12c.4.3.8.4 1.2.4.3 0 .6-.1.9-.2.7-.3 1.1-1 1.1-1.8V12c0-.8-.4-1.5-1.1-1.8-.3-.1-.6-.2-.9-.2z"></path></svg> </div> <script>parcelRequire=function(e,r,t,n){var i,o="function"==typeof parcelRequire&&parcelRequire,u="function"==typeof require&&require;function f(t,n){if(!r[t]){if(!e[t]){var i="function"==typeof parcelRequire&&parcelRequire;if(!n&&i)return i(t,!0);if(o)return o(t,!0);if(u&&"string"==typeof t)return u(t);var c=new Error("Cannot find module '"+t+"'");throw c.code="MODULE_NOT_FOUND",c}p.resolve=function(r){return e[t][1][r]||r},p.cache={};var l=r[t]=new f.Module(t);e[t][0].call(l.exports,p,l,l.exports,this)}return r[t].exports;function p(e){return f(p.resolve(e))}}f.isParcelRequire=!0,f.Module=function(e){this.id=e,this.bundle=f,this.exports={}},f.modules=e,f.cache=r,f.parent=o,f.register=function(r,t){e[r]=[function(e,r){r.exports=t},{}]};for(var c=0;c<t.length;c++)try{f(t[c])}catch(e){i||(i=e)}if(t.length){var l=f(t[t.length-1]);"object"==typeof exports&&"undefined"!=typeof module?module.exports=l:"function"==typeof define&&define.amd?define(function(){return l}):n&&(this[n]=l)}if(parcelRequire=f,i)throw i;return f}({"A2T1":[function(require,module,exports) {
var n=!1,t=document.querySelector(".speaker"),e=function(){return n?t.classList.remove("off"):t.classList.add("off")};setInterval(function(){return fetch("/state.json").then(function(n){return n.json()}).then(function(t){n=t.switch,e()})},1e3),t.addEventListener("click",function(t){n=!n,e(),fetch(n?"/on":"/off",{method:"POST"}).then(function(n){return n.json()}).then(function(t){n=t.switch,e()})});
},{}]},{},["A2T1"], null)
//# sourceMappingURL=app.b4ea79d0.js.map</script>
</body></html>
)=====";
