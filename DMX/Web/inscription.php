<?php
    require_once("session.php");
    require_once("class/user.php");
    
    $User = new user($BDD);
?>
<!DOCTYPE html>
<html lang="fr">
    <head>
        <!-- Compatible / UTF / Viewport-->
        <meta charset="UTF-8">
            <meta http-equiv="X-UA-Compatible" content="IE=edge">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <!-- Informations Générales -->
            <title>Controleur - Inscription</title>
            <meta name='description' content='Controleur'>
            <link rel='shortcut icon' href='image/favicon.png'>
            <link rel="stylesheet" href="CSS/inscription.css">
    </head>
    <body class="text-center">
        <main class="form-signin">
            <form method="POST">
                <h1>Inscription</h1>
                <div class="inputs">
                    <input name="log" type="text"   placeholder="login" required>
                    <input name="name" type="text"  placeholder="nom" required>
                    <input name="prenom" type="text"  placeholder="prenom" required>
                    <input name="password" type="password"  placeholder="mots de passe" required>
                    <input name="conf_pass" type="password"  placeholder="Confirmation mot de passe" required>
                </div>
                <button  name="envoie" type="submit">Inscription</button>
                <p class="inscription">J'ai déjà un <span>compte</span>. me <a href="connexion.php"><span>connecter</span></a></p>
            </form>
            <?php
                if (isset($_POST['envoie']))
                {
                    $login = strip_tags($_POST['log']);
                    $mdp = strip_tags($_POST['password']);
                    $name = strip_tags($_POST['name']);
                    $prenom = strip_tags($_POST['prenom']);
                    $conf_pass = strip_tags($_POST['conf_pass']);
                    $erreur = $User->inscription($login, $mdp, $name, $prenom, $conf_pass);
                    echo "<p style=color:#FF0000><b>".$erreur."</b></p>";
                }   else
                {
                    echo "<p>&nbsp;</p>";
                }
            ?>
        </main>
    </body>
</html>