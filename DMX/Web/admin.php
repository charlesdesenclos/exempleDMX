<?php 
        require_once("session.php");
        require_once("class/user.php");
        $User = new user($BDD);
        $User->getuser($_SESSION['id']);
        if (isset($_POST['deconnexion'])){
        $User->deconnexion();
        }
         if (isset($_GET['supr'])){
        $User->removeUser($_GET['supr']);
        
    }
    ?>
 
 
<!DOCTYPE html>
<html lang="en">
<head>
        <!-- Compatible / UTF / Viewport-->
            <meta charset="UTF-8">
            <meta http-equiv="X-UA-Compatible" content="IE=edge">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <!-- Informations Générales -->
            <title>Controleur - Panel Admin</title>
            <meta name='description' content='Controleur'>
            <link rel='shortcut icon' href='image/favicon.png'>

            <meta name='author' content='https://github.com/nicolas-dealmeida/DMX---WebSocket'>
            <link rel="stylesheet" href="CSS/admin.css">
            <link rel="stylesheet" href="CSS/style.css">
</head>
<body>
      <div class="container">
            <div class="table-responsive">
                <div class="table-wrapper">
                    <div class="table-title">
                        <div class="row">
                            <div class="col-sm-5">
                                <h2>panel administrateur</h2>
                            </div>
                        </div>
                    </div>
                    <table class="table">
                        <thead>
                            <tr>
                                <th>Id</th>
                                <th>Nom</th>
                                <th>Prenom</th>
                                <th>Pseudo</th>
                                <th>Mots de passe</th>
                                <th>Type Utilisateur</th>
                                <th>Action</th>
                            </tr>
                        </thead>
                        <tbody>
                            <?php
                                $User->giveuser();
                            ?>
                        </tbody>
                    </table>
                </div>
            </div>
        </div>
</body>
</html>
 
