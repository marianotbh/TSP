<?php
    include("./Clases/Persona.php");
    class BD 
    {
        private $con;
        private $user;
        private $clave;
        private $pdo;
        private $isinit = false;

        private function __construct()
        {
            if($isinit == false)
            {
                $con = "mysql:host=localhost;dbname=cdcol;charset=utf8";
                $user = "root";
                $clave = "";
                $pdo = new PDO($con, $user, $clave);
                $this->isinit = true;
            }
        }

        private function init()
        {
            self::__construct();
        }

        function Cargar($persona)
        {
            $this->init();
            $qry = "INSERT INTO Personas(Nombre, Apellido, DNI, Legajo, Foto) VALUES('$persona->nombre', '$persona->apellido', '$persona->dni', '$persona->legajo', '$persona->foto')";
            $this->EjecutarQuery($qry);
        }

        function Modificar($persona)
        {
            $this->init();
            $qry = "UPDATE Personas SET Nombre='$persona->nombre', Apellido='$persona->apellido', DNI='$persona->dni', Foto='$persona->foto' WHERE Legajo='$persona->legajo'";
            $this->EjecutarQuery($qry);
        }

        function Borrar($legajo)
        {
            $this->init();
            $qry = "DELETE FROM Personas WHERE Legajo='$legajo'";
            $this->EjecutarQuery($qry);
        }

        private function EjecutarQuery($string)
        {
            $sql = $comm->query($string);
            $res = $sql->execute();
        }
    }
?>