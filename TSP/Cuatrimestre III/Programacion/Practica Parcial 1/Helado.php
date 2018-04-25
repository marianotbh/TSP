<?php
    include_once("./IVendible.php");
    class Helado implements IVendible
    {
        private $sabor;
        private $precio;
        private $foto;

        function __construct($s, $p, $f)
        {
            $this->sabor = $s;
            $this->precio = $p;
            $this->foto = $f;
        }

        function cargarHelado($helado)
        {
            $ref = fopen("helados/sabores.txt","w");
            fwrite($ref, $helado->ToString());
            $this->cargarFoto($this->foto);
            fclose($ref);
        }

        function cargarFoto($file)
        {
            $ext = explode(".", $file["name"]);
            $hora = date("His");
            $foto = $this->sabor.".".$date.".".$ext[1];
            if(move_uploaded_file($file["tmp_name"], "./heladosImagen/$foto"))
                echo "<p>Archivo movido con exito</p>";
        }

        function ToString()
        {
            return "$this->sabor-$this->precio-$this->foto".PHP_EOL;
        }

        function vender($sabor, $qty)
        {
            $refSabores = fopen("./helados/heladosSabores.txt", "r");
            $refVendidos;
            $total = "El helado no se encuentra en la lista de sabores";
            $h;
            while(!feof($refSabores))
            {
                $h = explode(fgets($refSabores));
                if(count($h) == 3)
                {
                    $h = new Helado($h[0], $h[1], $h[2]);
                    if($h->sabor == $sabor)
                    {
                        $total = $h->PrecioMasIva() * $qty;
                        $refVendidos = fopen("./helados/heladosVendidos.txt", "a+");
                        fwrite($refVendidos, "$sabor-$qty-$total");
                        fclose($refVendidos);                        
                    }
                }
            }
            fclose($refSabores);
            return $total;
        }

        function ListadoHelados()
        {
            $ref = fopen("./helados/heladosSabores.txt", "r");
            $h;
            $tabla = "<table><tr><th>Sabor</th><th>Precio</th><th>Foto</th></tr>";
            while(!feof($ref))
            {
                $h = explode("-", fgets($ref));
                if(count($h) == 3)
                {
                    $h = new Helado($h[0],$h[1],$h[2]);
                    $tabla .= "<tr><td>$h->sabor</td><td>$h->precio</td><td><img src='localhost:8080/Practica Parcial 1/heladosImagen/$h->foto'/></td></tr>";
                }
            } 
            fclose($ref);
            return $tabla .= "</table>";
        }

        function borrarHeladoPOST()
        {
            $ret = $this->borrarHeladoGET();
            if($ret == "El sabor se encuentra en la lista")
            {
                $origen = "./heladosImagen/$this->foto";
                $newname = implode(".", array_splice(explode(".", $this->foto), 1, 0, "borrado"));
                $destino = "./heladosBorrados/$newname";
                if(copy(trim($origen), trim($destino)))
                    echo "<p>Foto movida a heladosBorrados</p>";
                else 
                    echo "err";
                $this->buscarYborrar();
            }
            return $ret;
            
        }
        function borrarHeladoGET()
        {
            $ret = "El sabor no se encuentra en la lista";
            if($this->buscarPorSabor() != null)
            {
                $ret = "El sabor se encuentra en la lista";
            }
            return $ret;
        }

        function modificarHelado($sabor, $precio, $foto)
        {
            $h = null;
            $hs;
            $key;
            if(($h = $this->buscarPorSabor()) != null)
            {
                $hs = $this->levantarArrayDeArchivo();
                $key = $hs[array_search($h,$hs)];
                $h->sabor = $sabor;
                $h->precio = $precio;
                $h->foto = $foto;
                $hs[$key] = $h;
            }
        }

        function PrecioMasIva()
        {
            return $this->precio + ($this->precio * 0.21);
        }

        function buscarPorSabor()
        {
            $ret = null;
            if(($helados = $this->levantarArrayDeArchivo("./helados/heladosSabores.txt",3,"-")) != null)
            {
                foreach($helado as $h)
                {
                    if($this->sabor == $h->sabor)
                    {
                        $ret = $h;
                    }
                }
            }
            return $ret;
        }

        function buscarYBorrar()
        {
            $ret = false;
            if(($helados = $this->levantarArrayDeArchivo("./helados/heladosSabores.txt",3,"-")) != null)
            {
                foreach($helados as $h)
                {
                    unset($helados[array_search($h,$helados)]);
                    $this->bajarArrayAArchivo($helados,"./helados/heladosSabores.txt",$ToString);
                    $ret = true;
                }
            }
            return $ret;
        }


        function levantarArrayDeArchivo($file, $objProperties, $delimiter)
        {
            $obj;
            $arr = null;
            $ref = fopen($file, "r");
            while(!feof($ref))
            {
                if(count($obj = explode($delimiter, fgets($ref))) == $objProperties)
                {
                    $arr[] = $obj;
                }
            }
            fclose($ref);
            return $arr;
        }

        function bajarArrayAArchivo($arr,$file)
        {
            $ref = fopen($file, "w");
            foreach($arr as $obj)
            {
                fwrite($ref,$obj->toString());
            }
            fclose($ref);
        }
    }