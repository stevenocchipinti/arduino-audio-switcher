let state = false
const speakerEl = document.querySelector(".speaker")

const render = () =>
  state ? speakerEl.classList.remove("off") : speakerEl.classList.add("off")

setInterval(() => (
  fetch("/state.json")
    .then(response => response.json())
    .then(data => {
      state = data.switch
      render()
    })
), 1000)

speakerEl.addEventListener("click", e => {
  // Eager update
  state = !state
  render()

  fetch(state ? "/on" : "/off", {method: "POST"})
    .then(response => response.json())
    .then(data => {
      state = data.switch
      render()
    })
})
