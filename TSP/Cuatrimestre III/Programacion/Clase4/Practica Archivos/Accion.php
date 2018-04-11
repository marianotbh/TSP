<?php
    include_once("../Entidades/Persona.php");

    ValidarFoto($_FILES["foto"])

    $p = new Persona($_POST["nombre"], $_POST["apellido"], $_POST["dni"], $_POST["legajo"], $_FILES["foto"]);

    switch($_POST["btn"])
    {
        case "Cargar":
            if($p->CargarPersona())
                echo "Cargado";
            break;
        case "Modificar":
            if($p->ModificarPersona())
                echo "Modificado";
            break;
        case "Borrar":
            if($p->BorrarPersona())
                echo "Borrado";
            break;
    }

    function ValidarFoto($file)
    {
        $imgTypes = array("jpg", "png", "bmp", "gif", "tif", "jpeg");
        $ext = explode(".", $file["name"]);
        if($file["size"] >= 10000000 && in_array($ext[1], $imgTypes))
        {
            return true;
        }
        else
            return false;
    }
?>

<br><br><a href="html.html">VOLVER</a>