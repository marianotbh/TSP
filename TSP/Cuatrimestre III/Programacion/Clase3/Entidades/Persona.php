<?php
    class Persona
    {
        private $nombre;
        private $apellido;
        private $edad;
        private $legajo;

        function __construct($nom, $ape, $eda, $leg)
        {
            $this->nombre = $nom;
            $this->apellido = $ape;
            $this->edad = $eda;
            $this->legajo = $leg;
        }

        function __get($var)
        {
            return $this->$var;
        }
        function __set($var, $val)
        {
            $this->$var = $val;
        }

        function __toString()
        {
            return "$this->nombre-$this->apellido-$this->edad-$this->legajo".PHP_EOL;
        }

        function CargarPersona($p)
        {
            $ppl = LevantarPersonas("Lista.txt");
            foreach($ppl as $peep)
            {
                if($peep == $p)
                    return false;
            }
            $ppl[] = $p;
            BajarPersonas($ppl, "Lista.txt");
            return true;
        }
    
        function ModificarPersona($p)
        {
            $ppl = LevantarPersonas("Lista.txt");
            foreach($ppl as $peep)
            {
                if($peep == $p)
                {
    
                }
            }
            return false;
        }
    
        function BorrarPersona($p)
        {
            
        }
    
        function LevantarPersonas($file)
        {
            $ref = fopen($file, "r");
            while(!feof($ref))
            {
                $persona = explode("-", fgets($ref));
                if(count($persona) == 4)
                {
                    $personas[] = new Persona($persona[0], $persona[1], $persona[2], $persona[3]);
                }
            }
            fclose($ref);
            return $personas;
        }

        function BajarPersonas($ppl, $file)
        {
            $ref = fopen($file, "w");
            foreach($ppl as $peep)
            {
                fwrite($ref, "$peep");
            }
            fclose($ref);
        }
    }

?>