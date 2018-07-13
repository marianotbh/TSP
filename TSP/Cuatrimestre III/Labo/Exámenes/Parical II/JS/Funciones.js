var Facultad;
(function (Facultad) {
    var Funciones = /** @class */ (function () {
        function Funciones() {
        }
        Funciones.LoadForm = function (id) {
            for (var i = 0; i < this.listaClientes.length; i++) {
                var cliente = this.listaClientes[i];
                if (cliente.getID() === id) {
                    $("#id").val(cliente.getID());
                    $("#nombre").val(cliente.getNombre());
                    $("#apellido").val(cliente.getApellido());
                    $("#edad").val(cliente.getEdad());
                    $("#sexo").val(cliente.getSexo());
                    break;
                }
            }
        };
        Funciones.Delete = function () {
            var id = Number($("#id").val());
            var flagBorro = false;
            for (var i = 0; i < this.listaClientes.length; i++) {
                var cliente = this.listaClientes[i];
                if (cliente.getID() === id) {
                    this.listaClientes.splice(i, 1);
                    flagBorro = true;
                    break;
                }
            }
            if (!flagBorro) {
                alert("No se encontró coincidencia con el ID.");
            }
            localStorage.setItem("clientes", this.ClientsToJSON());
            this.tablify(this.listaClientes);
            this.ClearForm();
        };
        Funciones.GetHighestID = function () {
            var IDMasAlto = this.listaClientes.reduce(function (IDMasAlto, cliente, i, array) {
                if (cliente.getID() > IDMasAlto) {
                    IDMasAlto = cliente.getID();
                }
                return IDMasAlto;
            }, 0);
            return IDMasAlto;
        };
        Funciones.Save = function () {
            var nombre = String($("#nombre").val());
            var apellido = String($("#apellido").val());
            var edad = Number($("#edad").val());
            var sexo = String($("#sexo").val());
            var cliente = new Cliente(this.GetHighestID() + 1, nombre, apellido, edad, sexo);
            this.listaClientes.push(cliente);
            localStorage.setItem("clientes", this.ClientsToJSON());
            this.tablify(this.listaClientes);
            this.ClearForm();
        };
        Funciones.ClientsToJSON = function () {
            if (this.listaClientes.length > 0) {
                var listaJson_1 = "[";
                this.listaClientes.forEach(function (cliente) {
                    listaJson_1 += cliente.toJSON();
                    listaJson_1 += ",";
                });
                listaJson_1 = listaJson_1.slice(0, -1);
                listaJson_1 += "]";
                return listaJson_1;
            }
            return "";
        };
        Funciones.LLToList = function () {
            var LSString = String(localStorage.getItem("clientes"));
            if (LSString != null && LSString != "") {
                var listaJson = JSON.parse(LSString);
                {
                    if (listaJson != null) {
                        for (var i = 0; i < listaJson.length; i++) {
                            var id = listaJson[i].id;
                            var nombre = listaJson[i].nombre;
                            var apellido = listaJson[i].apellido;
                            var edad = listaJson[i].edad;
                            var sexo = listaJson[i].sexo;
                            var cliente = new Cliente(id, nombre, apellido, edad, sexo);
                            this.listaClientes.push(cliente);
                        }
                    }
                }
            }
        };
        Funciones.ClearForm = function () {
            $("#nombre").val("");
            $("#apellido").val("");
            $("#edad").val("");
            $("#sexo").val("Masculino");
            $("#nombre").removeClass("is-invalid");
            $("#nmfb").hide();
            $("#apellido").removeClass("is-invalid");
            $("#lnfb").hide();
            $("#edad").removeClass("is-invalid");
            $("#agfb").hide();
            this.nombreValido = false;
            this.apellidoValido = false;
            this.edadValido = false;
        };
        Funciones.Checkbox_OnChange = function () {
            this.tablify(this.listaClientes);
        };
        Funciones.tablify = function (arrayClientes) {
            var mostrarID = Boolean($("#mostrarID").is(":checked"));
            var mostrarNombre = Boolean($("#mostrarNombre").is(":checked"));
            var mostrarApellido = Boolean($("#mostrarApellido").is(":checked"));
            var mostrarEdad = Boolean($("#mostrarEdad").is(":checked"));
            var mostrarSexo = Boolean($("#mostrarSexo").is(":checked"));
            var html = "<thead>" +
                "<tr>";
            if (mostrarID) {
                html += "<th>ID</th>";
            }
            if (mostrarNombre) {
                html += "<th>Nombre</th>";
            }
            if (mostrarApellido) {
                html += "<th>Apellido</th>";
            }
            if (mostrarEdad) {
                html += "<th>Edad</th>";
            }
            if (mostrarSexo) {
                html += "<th>Sexo</th>";
            }
            html += "</tr>" +
                "</thead>" +
                "<tbody>";
            arrayClientes.forEach(function (cliente) {
                html += "<tr onclick='Facultad.Funciones.LoadForm(" + cliente.getID() + ")'>";
                if (mostrarID) {
                    html += "<td>" + cliente.getID() + "</td>";
                }
                if (mostrarNombre) {
                    html += "<td>" + cliente.getNombre() + "</td>";
                }
                if (mostrarApellido) {
                    html += "<td>" + cliente.getApellido() + "</td>";
                }
                if (mostrarEdad) {
                    html += "<td>" + cliente.getEdad() + "</td>";
                }
                if (mostrarSexo) {
                    html += "<td>" + cliente.getSexo() + "</td>";
                }
                html += "</tr>";
            });
            html += "</tbody>";
            $("#tabla").html(html);
        };
        Funciones.FilterByName = function () {
            var filtro = String($("#txtFiltroNombre").val());
            var arrayFiltrado = this.listaClientes.filter(function (Cliente, i, array) {
                if (Cliente.getNombre().match("^" + filtro + "[a-zA-Z\s]*")) {
                    return true;
                }
                return false;
            });
            this.tablify(arrayFiltrado);
        };
        Funciones.OnLoad = function () {
            this.LLToList();
            this.tablify(this.listaClientes);
        };
        Funciones.CheckName = function () {
            var nombre = String($("#nombre").val());
            if (nombre === "" || !nombre.match("^[a-zA-Z]*$")) {
                $("#nombre").addClass("is-invalid");
                $("#nmfb").show();
                this.nombreValido = false;
            }
            else {
                $("#nombre").removeClass("is-invalid");
                $("#nmfb").hide();
                this.nombreValido = true;
            }
        };
        Funciones.CheckLastName = function () {
            var apellido = String($("#apellido").val());
            if (apellido === "" || !apellido.match("^[a-zA-Z]*$")) {
                $("#apellido").addClass("is-invalid");
                $("#lnfb").show();
                this.apellidoValido = false;
            }
            else {
                $("#apellido").removeClass("is-invalid");
                $("#lnfb").hide();
                this.apellidoValido = true;
            }
        };
        Funciones.CheckAge = function () {
            var edad = Number($("#edad").val());
            if (edad < 1 || edad > 99) {
                $("#edad").addClass("is-invalid");
                $("#agfb").show();
                this.edadValido = false;
            }
            else {
                $("#edad").removeClass("is-invalid");
                $("#agfb").hide();
                this.edadValido = true;
            }
        };
        Funciones.CheckBeforeSaving = function () {
            this.CheckAge();
            this.CheckName();
            this.CheckLastName();
            if (this.nombreValido && this.apellidoValido && this.edadValido) {
                this.Save();
            }
        };
        Funciones.Stats = function () {
            var totalEdades = this.listaClientes.reduce(function (total, cliente) {
                return total += cliente.getEdad();
            }, 0);
            var promedio = totalEdades / this.listaClientes.length;
            $("#txtPromedio").val(String(promedio));
        };
        Funciones.CleanLL = function () {
            localStorage.setItem("clientes", "");
        };
        Funciones.listaClientes = new Array();
        Funciones.nombreValido = false;
        Funciones.apellidoValido = false;
        Funciones.edadValido = false;
        return Funciones;
    }());
    Facultad.Funciones = Funciones;
})(Facultad || (Facultad = {}));
