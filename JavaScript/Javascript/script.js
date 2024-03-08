function hello(){
    const id = document.getElementById("salman");
    const newDiv =document.createElement("div")
    newDiv.style.color="green";
    newDiv.innerHTML ="Hello"
    const btn = document.createElement("button");
    btn.innerHTML ="Click"
    btn.addEventListener("click",function(){
        event.preventDefault();
        alert("Hello");
    });
    id.append(newDiv)
    id.append(btn);

}
hello()



