let speakers = false
const speakerEl = document.querySelector(".speaker")
const blindsUpEl = document.querySelector(".blinds-up")
const blindsDownEl = document.querySelector(".blinds-down")

const render = () =>
  speakers ? speakerEl.classList.remove("off") : speakerEl.classList.add("off")

setInterval(
  () =>
    fetch("/state.json")
      .then(response => response.json())
      .then(data => {
        speakers = data.speakers
        render()
      }),
  1000
)

speakerEl.addEventListener("click", e => {
  // Eager update
  speakers = !speakers
  render()

  fetch(speakers ? "/on.json" : "/off.json", { method: "POST" })
    .then(response => response.json())
    .then(data => {
      speakers = data.speakers
      render()
    })
})

blindsUpEl.addEventListener("click", e => fetch("/up.json", { method: "POST" }))
blindsDownEl.addEventListener("click", e =>
  fetch("/down.json", { method: "POST" })
)
