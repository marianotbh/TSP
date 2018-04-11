<?php
    include_once("../Entidades/Persona.php");

    $ext = explode(".", $_FILES["foto"]["name"]);
    $foto = "foto_".$_POST["legajo"].".".$ext[1];
    if(move_uploaded_file($_FILES["foto"]["tmp_name"], "../img/$foto"))
        echo "<p>archivo movido con exito</p>";

    $p = new Persona($_POST["nombre"], $_POST["apellido"], $_POST["dni"], $_POST["legajo"], $foto);
    

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
?>

<br><br><a href="index.php">VOLVER</a>