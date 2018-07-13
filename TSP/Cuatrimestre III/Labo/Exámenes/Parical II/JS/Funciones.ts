namespace Facultad {
    export class Funciones {
        private static listaClientes: Array<Cliente> = new Array();
        private static nombreValido: boolean = false;
        private static apellidoValido: boolean = false;
        private static edadValido: boolean = false;

        public static LoadForm(id: number) {
            for (var i = 0; i < this.listaClientes.length; i++) {
                let cliente: Cliente = this.listaClientes[i];
                if (cliente.getID() === id) {
                    $("#id").val(cliente.getID());
                    $("#nombre").val(cliente.getNombre());
                    $("#apellido").val(cliente.getApellido());
                    $("#edad").val(cliente.getEdad());
                    $("#sexo").val(cliente.getSexo());
                    break;
                }
            }
        }
        public static Delete() {
            let id: number = Number($("#id").val());
            let flagBorro: boolean = false;
            for (var i = 0; i < this.listaClientes.length; i++) {
                let cliente = this.listaClientes[i];
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
        }
        public static GetHighestID(): number {
            let IDMasAlto: number = this.listaClientes.reduce(function (IDMasAlto, cliente, i, array) {
                if (cliente.getID() > IDMasAlto) {
                    IDMasAlto = cliente.getID();
                }
                return IDMasAlto;
            }, 0);
            return IDMasAlto;
        }
        public static Save(): void {
            let nombre: string = String($("#nombre").val());
            let apellido: string = String($("#apellido").val());
            let edad: number = Number($("#edad").val());
            let sexo: string = String($("#sexo").val());
            let cliente = new Cliente(this.GetHighestID() + 1, nombre, apellido, edad, sexo);
            this.listaClientes.push(cliente);
            localStorage.setItem("clientes", this.ClientsToJSON());
            this.tablify(this.listaClientes);
            this.ClearForm();
        }
        private static ClientsToJSON(): string {
            if (this.listaClientes.length > 0) {
                let listaJson: string = "[";
                this.listaClientes.forEach(function (cliente) {
                    listaJson += cliente.toJSON();
                    listaJson += ",";
                });
                listaJson = listaJson.slice(0, -1);
                listaJson += "]";
                return listaJson;
            }
            return "";
        }
        private static LLToList(): void {
            let LSString: string = String(localStorage.getItem("clientes"));
            if (LSString != null && LSString != "") {
                let listaJson = JSON.parse(LSString);
                {
                    if (listaJson != null) {
                        for (var i = 0; i < listaJson.length; i++) {
                            let id = listaJson[i].id;
                            let nombre = listaJson[i].nombre;
                            let apellido = listaJson[i].apellido;
                            let edad = listaJson[i].edad;
                            let sexo = listaJson[i].sexo;

                            var cliente = new Cliente(id, nombre, apellido, edad, sexo);
                            this.listaClientes.push(cliente);
                        }
                    }
                }
            }
        }
        public static ClearForm(): void {
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
        }
        public static Checkbox_OnChange(): void {
            this.tablify(this.listaClientes);
        }
        public static tablify(arrayClientes: Array<Cliente>): void {
            let mostrarID: boolean = Boolean($("#mostrarID").is(":checked"));
            let mostrarNombre: boolean = Boolean($("#mostrarNombre").is(":checked"));
            let mostrarApellido: boolean = Boolean($("#mostrarApellido").is(":checked"));
            let mostrarEdad: boolean = Boolean($("#mostrarEdad").is(":checked"));
            let mostrarSexo: boolean = Boolean($("#mostrarSexo").is(":checked"));
            let html = "<thead>" +
                "<tr>";
            if (mostrarID) {
                html += "<th>ID</th>";
            } if (mostrarNombre) {
                html += "<th>Nombre</th>";
            } if (mostrarApellido) {
                html += "<th>Apellido</th>";
            } if (mostrarEdad) {
                html += "<th>Edad</th>";
            } if (mostrarSexo) {
                html += "<th>Sexo</th>";
            }
            html += "</tr>" +
                "</thead>" +
                "<tbody>";
            arrayClientes.forEach(function (cliente) {
                html += "<tr onclick='Facultad.Funciones.LoadForm(" + cliente.getID() + ")'>";
                if (mostrarID) {
                    html += "<td>" + cliente.getID() + "</td>";
                } if (mostrarNombre) {
                    html += "<td>" + cliente.getNombre() + "</td>";
                } if (mostrarApellido) {
                    html += "<td>" + cliente.getApellido() + "</td>";
                } if (mostrarEdad) {
                    html += "<td>" + cliente.getEdad() + "</td>";
                } if (mostrarSexo) {
                    html += "<td>" + cliente.getSexo() + "</td>";
                }
                html += "</tr>";
            });
            html += "</tbody>";
            $("#tabla").html(html);
        }
        public static FilterByName(): void {
            let filtro: String = String($("#txtFiltroNombre").val());
            let arrayFiltrado: Array<Cliente> = this.listaClientes.filter(function (Cliente: Cliente, i: Number, array: Array<Cliente>) {
                if (Cliente.getNombre().match("^" + filtro + "[a-zA-Z\s]*")) {
                    return true;
                }
                return false;
            });
            this.tablify(arrayFiltrado);
        }
        public static OnLoad(): void {
            this.LLToList();
            this.tablify(this.listaClientes);
        }
        public static CheckName(): void {
            let nombre: string = String($("#nombre").val());
            if (nombre === "" || !nombre.match("^[a-zA-Z]*$")) {
                $("#nombre").addClass("is-invalid");
                $("#nmfb").show();
                this.nombreValido = false;
            } else {
                $("#nombre").removeClass("is-invalid");
                $("#nmfb").hide();
                this.nombreValido = true;
            }
        }
        public static CheckLastName(): void {
            let apellido: string = String($("#apellido").val());

            if (apellido === "" || !apellido.match("^[a-zA-Z]*$")) {
                $("#apellido").addClass("is-invalid");
                $("#lnfb").show();
                this.apellidoValido = false;
            } else {
                $("#apellido").removeClass("is-invalid");
                $("#lnfb").hide();
                this.apellidoValido = true;
            }
        }
        public static CheckAge(): void {
            let edad: number = Number($("#edad").val());

            if (edad < 1 || edad > 99) {
                $("#edad").addClass("is-invalid");
                $("#agfb").show();
                this.edadValido = false;
            } else {
                $("#edad").removeClass("is-invalid");
                $("#agfb").hide();
                this.edadValido = true;
            }
        }
        public static CheckBeforeSaving(): void {
            this.CheckAge();
            this.CheckName();
            this.CheckLastName();
            if (this.nombreValido && this.apellidoValido && this.edadValido) {
                this.Save();
            }
        }
        public static Stats(): void {
            let totalEdades: number = this.listaClientes.reduce(function (total, cliente) {
                return total += cliente.getEdad();
            }, 0);
            let promedio: number = totalEdades / this.listaClientes.length;
            $("#txtPromedio").val(String(promedio));
        }
        public static CleanLL() {
            localStorage.setItem("clientes", "");
        }
    }
}