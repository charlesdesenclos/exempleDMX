<?php 
     // demarrage de la session
     if(isset($_POST["deco"])){
        $_SESSION["Logged"] = false;
        session_destroy();
        
    }
    header('Location:index.php'); // On redirige
?>
