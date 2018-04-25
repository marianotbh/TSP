<?php 
    class Cliente 
    {
        private $nombre;
        private $correo;
        private $clave;

        function __construct($n, $c, $pw)
        {
            $this->nombre = $n;
            $this->correo = $c;
            $this->clave = $pw;
        }

        function ToString()
        {
            return "$this->nombre-$this->correo-$this->clave".PHP_EOL;
        }

        static function cargarCliente($nombre, $correo, $clave)
        {
            $c = new Cliente($nombre, $correo, $clave);
            $ref = fopen("./clientes/clientesActuales.txt", "w");
            fwrite($ref, $c->ToString());
            fclose($ref);
        }

        static function validar($correo, $clave)
        {
            $ref = fopen("./clientes/clientesActuales.txt", "r");
            $p;
            while(!feof($ref))
            {
                $p = explode(fgets($ref));
                if(count($p) == 3)
                {
                    if($p[1] == $correo && $p[2] == $clave)
                    {
                        return "Cliente logueado";
                    }
                }
            }
            fclose($ref);
            return "Cliente inexistente";
        }        
    }