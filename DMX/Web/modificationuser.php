<?php
    require_once("session.php");
    require_once("class/user.php");

    $User = new user($BDD);
    $admin = new user($BDD);
    $admin->getuser($_SESSION['id']);
    $User->getuser($_GET['modf']);
    
    if (!isset($_SESSION['id'])){
        header("Location: connexion.php");
    }
    if ($admin->getadmin() == 0){
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
            <title>Controleur - Modif User</title>
            <meta name='description' content='Controleur'>
            <link rel='shortcut icon' href='image/favicon.png'>
        <!-- Custom styles for this template -->
        <link rel="stylesheet" href="CSS/style.css" >
        <link rel="stylesheet" href="CSS/inscription.css" >
    </head>
    <body class="text-center">
        <main class="form-signin">
            <form method="POST">
                <h1 class="h3 mb-3 fw-normal">Modification User</h1>
                <div class="form-floating">
                    <input name="log" type="text" class="form-control" id="floatingInput" placeholder="login" value="<?= $User->getlogin() ?>" required>
                    <label for="floatingInput">Login</label>
                </div>
                <div class="form-floating">
                    <input name="name" type="text" class="form-control" id="floatingInput" placeholder="name" value="<?= $User->getnom() ?>" required>
                    <label for="floatingInput">Nom</label>
                </div>
                <div class="form-floating">
                    <input name="prenom" type="text" class="form-control" id="floatingInput" placeholder="prenom" value="<?= $User->getprenom() ?>" required>
                    <label for="floatingInput">Prénom</label>
                </div>
                <div class="form-floating">
                    <input name="pass" type="password" class="form-control" id="floatingPassword" placeholder="mots de passe" value="<?= $User->getmdp() ?>" required>
                    <label for="floatingPassword">Mots de passe</label>
                </div>
                <div class="form-floating">
                    <input name="conf_pass" type="password" class="form-control" id="floatingPassword" placeholder="Confirmation mot de passe" value="<?= $User->getmdp() ?>" required>
                    <label for="floatingPassword">Confirmer votre mots de passe</label>
                </div>
                <div class="form-check form-switch">
                    <?php
                        if ($User->getadmin() == 0){
                            ?>
                                <input class="form-check-input" type="checkbox" id="flexSwitchCheckDefault" name="admin" value="oui">
                            <?php
                        } else if ($User->getadmin() == 1){
                            ?>
                                <input class="form-check-input" type="checkbox" id="flexSwitchCheckDefault" name="admin" value="oui" checked>
                            <?php
                        }
                    ?>
                    <label class="form-check-label" for="flexSwitchCheckDefault">Admin</label>
                </div>
                <button class="w-100 btn btn-lg btn-primary" name="envoi" type="submit">Modifier</button>
            </form>
            <?php
                if (isset($_POST['envoi'])){
                    $login = strip_tags($_POST['log']);
                    $mdp = strip_tags($_POST['pass']);
                    $name = strip_tags($_POST['name']);
                    $prenom = strip_tags($_POST['prenom']);
                    $conf_pass = strip_tags($_POST['conf_pass']);
                    if (isset($_POST['admin'])){
                        $admin = "1";
                    } else{
                        $admin = '0';
                    }
                    $erreur = $User->updateUser($login, $mdp, $name, $prenom, $conf_pass, $admin);
                    echo "<p style=color:#FF0000><b>" . $erreur . "</b></p>";
                } else{
                    echo "<p>&nbsp;</p>";
                }
            ?>
            <input type="button" value="Annuler" class="w-100 btn btn-lg btn-primary" onClick="window.location.href='admin.php'" />
        </main>
    </body>
</html>