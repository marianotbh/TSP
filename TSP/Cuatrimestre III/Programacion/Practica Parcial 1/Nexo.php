<?php
    include_once("./Cliente.php");
    include_once("./Helado.php");
    if(isset($_POST))
    {
        switch($_POST["accion"])
        {
            case "cargarCliente":
                Cliente::cargarCliente($_POST["nombre"], $_POST["correo"], $_POST["clave"]);
                break;
            case "validar":
                Cliente::validar($_POST["correo"], $_POST["clave"]);
                break;
            case "cargarHelado":
                break;
            case "borrarHelados":
                break;
        }
    } else if(isset($_GET))
    {
        switch($_GET["accion"])
        {
            case "vender":
                break;
            case "ListadoHelados":
                break;
            case "borrarHelados":
                break;
        }
    }
?>

<br><br><a href="html.html">VOLVER</a>