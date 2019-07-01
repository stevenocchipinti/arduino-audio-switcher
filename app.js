let state = false
const speakerEl = document.querySelector(".speaker")

speakerEl.addEventListener(
  "click",
  e => {
    state ? speakerEl.classList.remove("off") : speakerEl.classList.add("off")
    state = !state
  }
)
