var httpReq = new XMLHttpRequest();

var callback = function () {
    if (httpReq.readyState == 4) {
        if (httpReq.status == 200) {
            var json = JSON.parse(httpReq.responseText);
            console.log(json);
            if (json != null && (json.type == "Admin" || json.type == "User")) {
                localStorage.setItem("type", json.type);
                window.location.href = "../INDEX/index.html";
            } else if (json != null && json.type == "error") {
                err();
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
    ajax("POST", JSON.stringify(datosLogin), "http://localhost:3000/login", callback);
}

function getNotas() {
    if (httpReq.readyState == 4) {
        if (httpReq.status == 200) {
            json = JSON.parse(httpReq.responseText);
            tablify(json);
        }
    }
}

function tablify(arr) {
    var i;
    html = '';
    type = localStorage.getItem("type");
    for (i = 0; i < arr.length; i++) {
        obj = arr[i];
        if (obj.nota < 4) {
            html += "<tr style='color:red' align='center'>";
        } else if (obj.nota >= 4) {
            html += "<tr align='center'>";
        }
        html += '<td>' + obj.id + '</td><td>' + obj.legajo + '</td><td>' + obj.nombre + '</td><td>' + obj.materia + '</td><td>' + obj.nota + '</td>';
        if (type == "Admin") {
            html += "<td><input type='button' value='Editar' onClick=hide()/></td></tr>";
        } else if (type == "User") {
            html += "</tr>";
        }
    }
    document.getElementById('tbody').innerHTML = html;
}

function edit() {
    var leg = document.getElementById("legajo").value;
    var nom = document.getElementById("nombre").value;
    var mat = document.getElementById("materia").value;
    var not = document.getElementById("nota").value;
    var datosPost = {
        legajo: leg,
        nombre: nom,
        materia: mat,
        nota: not
    }
    ajax("POST", JSON.stringify(datosPost), "http://localhost:3000/editarNota", getNotas);
}

function err() {
    document.getElementById("correo").className = " err";
    document.getElementById("pw").className = " err";
    document.getElementById("errMsg").innerHTML = "Correo o contraseña incorrectos";
}

function hide(legajo, nombre, materia, nota) {
    if (document.getElementById("editNota").className == "hidden") {
        document.getElementById("editNota").className = "shown";
    }
    else if (document.getElementById("editNota").className == "shown") {
        document.getElementById("editNota").className = "hidden";
    }
    document.getElementById("legajo").value = legajo;
    document.getElementById("nombre").value = nombre;
    document.getElementById("materia").value = materia;
    document.getElementById("nota").value = nota;

}

window.onload = ajax("GET", "", "http://localhost:3000/notas", getNotas);



