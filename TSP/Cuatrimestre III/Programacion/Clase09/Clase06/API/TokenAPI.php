<?php
include_once("Entidades/Token.php");
include_once("Entidades/Usuario.php");
class TokenApi extends Token{
    public function GenerarToken($request, $response, $args){
        $parametros = $request->getParsedBody();
        $user = $parametros["user"];
        $password  = $parametros["password"];
        $login = Usuario::Login($user,$password);
        if($login[0] > 0){
            $token = Token::CodificarToken($user);
            $respuesta = array("Estado" => "OK", "Mensaje" => "OK", "Token" => $token);
            
        }
        else{
            $respuesta = array("Estado" => "ERROR", "Mensaje" => "Usuario o clave invalidos.");
        }
        $newResponse = $response->withJson($respuesta,200);
        return $newResponse;
    }

    public function ValidarToken($request, $response, $args){
        $token = $request->getHeader("token");
        $parametros = $request->getParsedBody();
        $user = $parametros["user"];
        $respuesta = Token::DecodificarToken($user,$token[0]);
        $newResponse = $response->withJson($respuesta,200);
        return $newResponse;
    }
}