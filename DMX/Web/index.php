<!DOCTYPE html>
<html lang="en">
    <head>
        <!-- Compatible / UTF / Viewport-->
        <meta charset="UTF-8">
            <meta http-equiv="X-UA-Compatible" content="IE=edge">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <!-- Informations Générales -->
            <title>Controleur</title>
            <meta name='description' content='Controleur'>
            <link rel='shortcut icon' href='image/favicon.png'>
            <link rel="stylesheet" href="CSS/style.css" >
    </head>
    <body>
        <?php
            if(isset($_SESSION['id'])){
                include("index.php");
            } else{
                include("connexion.php");
            }
        ?>
    </body>
</html>