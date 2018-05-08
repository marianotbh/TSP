<?php
    function DropToFile($arr, $file)
    {
        $ref = fopen($file, "w");
        foreach($arr as $obj)
        {
            fwrite($ref, "$obj");
        }
        fclose($ref);
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
    
    function CargarFoto($nombre, $file, $fileFolder)
    {
        $ext = explode(".", $file["name"]);
        $foto = "foto_".$nombre.".".$ext[1];
        if(move_uploaded_file($file["tmp_name"], "./img/$foto"))
            echo "<p>Archivo movido con exito</p>";
        return $foto;
    }

    function BackUp($file, $backupFolder)
    {
        $origen = "./img/$file";
        $destino = "./$backupFolder/backup_$file";
        if(copy(trim($origen), trim($destino)))
            echo "<p>Guardada copia de respaldo</p>";
    }
?>