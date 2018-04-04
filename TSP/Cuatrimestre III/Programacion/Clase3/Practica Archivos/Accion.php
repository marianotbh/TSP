<?php
    include_once("../Entidades/Persona.php");

    switch($_POST["btn"])
    {
        case "Cargar":
            CargarPersona(new Persona($_POST["nombre"], $_POST["apellido"], $_POST["dni"], $_POST["legajo"]));
            echo "Cargado";
            break;
        case "Modificar":
            echo "Modificado";
            break;
        case "Borrar":
            echo "Borrado";
            break;
    }
?>

<br><br><a href="index.php">VOLVER</a>