<?php
    require_once("session.php");
    require_once("class/user.php");

    $User = new user($BDD);
    
    if (isset($_SESSION['id'])){
        header("Location: accueil.php");
    }
?>
<!DOCTYPE html>
<html lang="fr">
    <head>
        <!-- Compatible / UTF / Viewport-->
        <meta charset="UTF-8">
            <meta http-equiv="X-UA-Compatible" content="IE=edge">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <!-- Informations Générales -->
            <title>Controleur - Connexion</title>
            <link rel="stylesheet" href="CSS/style.css">
            <link rel="stylesheet" href="CSS/inscription.css">
            <meta name='description' content='Controleur'>
            <link rel='shortcut icon' href='image/favicon.png'>
    </head>
    <body >
        
            <form method="POST" action="">
                
                <h1>Se connecter</h1>
                <div class="inputs">
                    <input name="log" type="text" class="form-control" id="floatingInput" placeholder="login" required>
                    <input name="password" type="password" class="form-control" id="floatingPassword" placeholder="Password" required>
                    
                </div>
                <div class="inscription"><a href="inscription.php">Inscription</a></div>
                <div class="connexion">
                    <button name="connexion" class="btn btn-"type="submit">Se connecter</button>
                </div>
            </form>
            <?php
                if(isset($_POST['connexion'])){
                    $login = strip_tags($_POST['log']);
                    $mdp = strip_tags($_POST['password']);
                    $erreur = $User->connexion($login, $mdp);
                    echo "<p style=color:#FF0000><b>".$erreur."</b></p>";
                }else{
                    echo "<p>&nbsp;</p>";
                }
            ?>
        
       
    </body>
</html>