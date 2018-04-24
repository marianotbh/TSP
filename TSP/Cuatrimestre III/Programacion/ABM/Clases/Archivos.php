<?php
    include("./Clases/BD.php");
        
    function act($action = "")
    {
        switch($action)
        {
            case "Cargar":
                $pers = new Persona($_POST["nombre"], $_POST["apellido"], $_POST["dni"], $_POST["legajo"], $_FILES["foto"]);
                if($pers->Cargar())
                    echo "Cargado";
                break;
            case "Modificar":
                $pers = new Persona($_POST["nombre"], $_POST["apellido"], $_POST["dni"], $_POST["legajo"], $_FILES["foto"]);
                if($pers->Modificar())
                    echo "Modificado";
                break;
            case "Borrar":
                $pers = new Persona($_POST["nombre"], $_POST["apellido"], $_POST["dni"], $_POST["legajo"], $_FILES["foto"]);
                if($pers->Borrar())
                    echo "Borrado";
                break;
            case "Listar":
                if($pers->Listar())
                    echo "Fin de lista";
                break;
            default:
                echo "Debe ingresar una opción válida";
                break;
        }
    }
    
    function ValidarFoto($file)
    {
        $imgTypes = array("jpg", "png", "bmp", "gif", "tif", "jpeg");
        $ext = explode(".", $file["name"]);
        echo $ext[1];
        if($file["size"] <= 10000000 && in_array($ext[1], $imgTypes))
        {
            return true;
        }
        return false;
    }
    
    function CargarFoto($file)
    {
        $ext = explode(".", $file["name"]);
        $foto = "foto_".$_POST["legajo"].".".$ext[1];
        if(move_uploaded_file($file["tmp_name"], "../img/$foto"))
            echo "<p>Archivo movido con exito</p>";
        return $foto;
    }

    function BackUp($file)
    {
        $origen = "../img/$file";
        $destino = "../backup/backup_$file";
        if(copy(trim($origen), trim($destino)))
            echo "<p>Guardada copia de respaldo</p>";
    }
?>