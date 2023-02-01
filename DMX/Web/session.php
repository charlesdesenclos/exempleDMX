<?php
    session_start();
    
    try{
        $BDD = new PDO('mysql:host=192.168.65.56;dbname=DMX; charset=utf8', 'userweb', 'userweb');
       
    }catch(Exception $e){
        die('Erreur : '. $e->getMessage());
    }
?>