var httpReq = new XMLHttpRequest();
var url = "http://localhost:1337/login";

var callback = function () {
    if (httpReq.readyState == 4) {
        if (httpReq.status == 200) {
            var json = JSON.parse(httpReq.responseText);
            console.log(json);
            if (json != null && json.autenticado === "si") {
                localStorage.setItem("prefs", JSON.stringify(json));
                window.location.href = "index.html";
            }
        }
    }
}

function ajax(metodo, parametros, url, callback) {
    httpReq.onreadystatechange = callback;
    if (metodo == "GET") {
        httpReq.open("GET", url, true);
        httpReq.send();
    } else if (metodo == "POST") {
        console.log("holi");
        httpReq.open("POST", url, true);
        httpReq.setRequestHeader("Content-type", "application/json");
        httpReq.send(parametros);
    }
}

function login() {
    var correo = document.getElementById("correo").value;
    var pw = document.getElementById("pw").value;
    localStorage.setItem("email", correo);
    var datosLogin = { email: correo, password: pw };
    ajax("POST", JSON.stringify(datosLogin), url, callback);
}

function newPost() {
    var texttitle = document.getElementById("texttitle").value;
    var textheader = document.getElementById("textheader").value;
    var posttext = document.getElementById("posttext").value;
    var author = document.getElementById("author").value;
    var datosPost = {
        title: texttitle,
        header: textheader,
        posttext: posttext,
        author: author
    }
    ajax("POST", JSON.stringify(datosPost), "http://localhost:1337/postearNuevaEntrada", crearPostHTML);
    
}

function crearPostHTML() {
    if (httpReq.readyState == 4) {
        if (httpReq.status == 200) {
            json = JSON.parse(httpReq.responseText);
            var title = "<h3>" + json.title + "</h3>";
            var head = "<header>" + json.header + "</header>";
            var body = "<div>" + json.posttext + "</div>";
            var author = "<p>" + json.author + "</p>";
            document.getElementById("container").innerHTML += "<article>" + title + head + body + author + "</article>";
        }
    }
}

function toggleHide(item) {
    if (document.getElementById("btnNewPost").value == "Nueva publicación")
        document.getElementById("btnNewPost").value = "Cancelar";
    else if (document.getElementById("btnNewPost").value == "Cancelar")
        document.getElementById("btnNewPost").value = "Nueva publicación";
    if (document.getElementById(item).className == "hidden")
        document.getElementById(item).className = "shown";
    else if (document.getElementById(item).className == "shown")
        document.getElementById(item).className = "hidden";
}



