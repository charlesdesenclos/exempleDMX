<?php
    require_once("session.php");
    require_once("class/user.php");

    $User = new user($BDD);
    $User->getuser($_SESSION['id']);
    
    if(!isset($_SESSION['id'])){
        header("Location: connexion.php");
    }
    if(isset($_GET['deconnexion'])){
        $User->deconnexion();
    }
    if(isset($_GET['administrateur'])){
        header("Location: admin.php");
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
                        <title>Controleur</title>
                        <meta name='description' content='Controleur'>
                        <link rel='shortcut icon' href='image/favicon.png'>
                        <link rel="stylesheet" href="CSS/style.css">
                        <meta name='author' content='https://github.com/nicolas-dealmeida/DMX---WebSocket'>
        <head>
        <body>
                <div class="bandeau">
                        <form class="DivUnlog">
                                <input type="submit" class="deconnexion" name="deconnexion" value="Déconnexion">
                                <?php
                                        if($User->getadmin() == 1){
                                                ?>
                                                        <div class="admin">
                                                                <input type="submit" class="administrateur" name="administrateur" value="Administrateur">
                                                        </div>
                                                <?php
                                        }
                                ?>
                        </form>
                </div>
                <form class="Lampes" action="">
                        <div class="SlideLampes">
                                <div class="Lampe">
                                        <h3 class="Title">Lampe N°1</h3>
                                        <div class="Lampe1">
                                                <div class="slidecontainer">
                                                        <input type="range" min="0" max="255" value="0" class="slider" id="slide01">
                                                        <p class="Red   P1">Valeur : <span id="value01"></span></p>
                                                </div>
                                                <div class="slidecontainer">
                                                        <input type="range" min="0" max="255" value="0" class="slider" id="slide02">
                                                        <p class="Green P2">Valeur : <span id="value02"></span></p>
                                                </div>
                                                <div class="slidecontainer">
                                                        <input type="range" min="0" max="255" value="0" class="slider" id="slide03">
                                                        <p class="Blue  P3">Valeur : <span id="value03"></span></p>
                                                </div>
                                                <div class="slidecontainer">
                                                        <input type="range" min="0" max="255" value="0" class="slider" id="slide04">
                                                        <p class="White P4">Valeur : <span id="value04"></span></p>
                                                </div>
                                        </div>
                                </div>
                                <div class="Lampe">
                                        <h3 class="Title">Lampe N°2</h3>
                                        <div class="Lampe2">
                                                <div class="slidecontainer">
                                                        <input type="range" min="0" max="255" value="0" class="slider" id="slide05">
                                                        <p class="Red   P5">Valeur : <span id="value05"></span></p>
                                                </div>
                                                <div class="slidecontainer">
                                                        <input type="range" min="0" max="255" value="0" class="slider" id="slide06">
                                                        <p class="Green P6">Valeur : <span id="value06"></span></p>
                                                </div>
                                                <div class="slidecontainer">
                                                        <input type="range" min="0" max="255" value="0" class="slider" id="slide07">
                                                        <p class="Blue  P7">Valeur : <span id="value07"></span></p>
                                                </div>
                                                <div class="slidecontainer">
                                                        <input type="range" min="0" max="255" value="0" class="slider" id="slide08">
                                                        <p class="White P8">Valeur : <span id="value08"></span></p>
                                                </div>
                                        </div>
                                </div>
                                <div class="Lampe">
                                        <h3 class="Title">Lampe N°3</h3>
                                        <div class="Lampe3">
                                                <div class="slidecontainer">
                                                        <input type="range" min="0" max="255" value="0" class="slider" id="slide09">
                                                        <p class="Red   P9">Valeur : <span id="value09"></span></p>
                                                </div>
                                                <div class="slidecontainer">
                                                        <input type="range" min="0" max="255" value="0" class="slider" id="slide10">
                                                        <p class="Green P10">Valeur : <span id="value10"></span></p>
                                                </div>
                                                <div class="slidecontainer">
                                                        <input type="range" min="0" max="255" value="0" class="slider" id="slide11">
                                                        <p class="Blue  P11">Valeur : <span id="value11"></span></p>
                                                </div>
                                                <div class="slidecontainer">
                                                        <input type="range" min="0" max="255" value="0" class="slider" id="slide12">
                                                        <p class="White P12">Valeur : <span id="value12"></span></p>
                                                </div>
                                        </div>
                                </div>
                        </div>
                        <div class="Buttons">
                                <div class="ButtonsControls">
                                        <div class="ButtonsGP1">
                                                <div class="AllColor">
                                                        <a class="NeonButton OnAllButton FlashButton" href="#">
                                                                <span></span>
                                                                <span></span>
                                                                <span></span>
                                                                <span></span>
                                                                Allumage Complet
                                                        </a>
                                                        <a class="NeonButton OffAllButton NoFlashButton" href="#">
                                                                <span></span>
                                                                <span></span>
                                                                <span></span>
                                                                <span></span>
                                                                Extinction Complet
                                                        </a>
                                                        <a class="NeonButton StartRandom FlashButton" href="#">
                                                                <span></span>
                                                                <span></span>
                                                                <span></span>
                                                                <span></span>
                                                                Allumage Random
                                                        </a>
                                                        <a class="NeonButton StopRandom NoFlashButton" href="#">
                                                                <span></span>
                                                                <span></span>
                                                                <span></span>
                                                                <span></span>
                                                                Extinction Random
                                                        </a>
                                                </div>
                                                <div class="Templates">
                                                        <a class="NeonButton AllumeFrance FranceButton" href="#">
                                                                <span></span>
                                                                <span></span>
                                                                <span></span>
                                                                <span></span>
                                                                Allumage France
                                                        </a>
                                                </div>
                                        </div>
                                        <div class="ButtonsGP2">
                                                <div class="ButtonsLampes">
                                                        <div class="LampeOn">
                                                                <a class="NeonButton AllumeLampe1 FlashButton" href="#">
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        Allumage Lampe 1
                                                                </a>
                                                                <a class="NeonButton AllumeLampe2 FlashButton" href="#">
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        Allumage Lampe 2
                                                                </a>
                                                                <a class="NeonButton AllumeLampe3 FlashButton" href="#">
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        Allumage Lampe 3
                                                                </a>
                                                        </div>
                                                        <div class="LampeOff">
                                                                <a class="NeonButton ResetLampe1 NoFlashButton" href="#">
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        Extinction Lampe 1
                                                                </a>
                                                                <a class="NeonButton ResetLampe2 NoFlashButton" href="#">
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        Extinction Lampe 2
                                                                </a>
                                                                <a class="NeonButton ResetLampe3 NoFlashButton" href="#">
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        Extinction Lampe 3
                                                                </a>
                                                        </div>
                                                </div>
                                                <div class="ButtonsColors">
                                                        <div class="ColorOn">
                                                                <a class="NeonButton AllumeRouge RedButton" href="#">
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        On Rouge
                                                                </a>
                                                                <a class="NeonButton AllumeVert GreenButton" href="#">
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        On Vert
                                                                </a>
                                                                <a class="NeonButton AllumeBleu BlueButton" href="#">
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        On Bleu
                                                                </a>
                                                                <a class="NeonButton AllumeBlanc WhiteButton" href="#">
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        On Blanc
                                                                </a>
                                                        </div>
                                                        <div class="ColorOff">
                                                                <a class="NeonButton ResetRouge RedButton" href="#">
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        Off Rouge
                                                                </a>
                                                                <a class="NeonButton ResetVert GreenButton" href="#">
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        Off Vert
                                                                </a>
                                                                <a class="NeonButton ResetBleu BlueButton" href="#">
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        Off Bleu
                                                                </a>
                                                                <a class="NeonButton ResetBlanc WhiteButton" href="#">
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        <span></span>
                                                                        Off Blanc
                                                                </a>
                                                        </div>
                                                </div>
                                        </div>
                                </div>
                        </div>
                </form>
                <script src="script.js"></script>
                <script src="index.js"></script>
        </body>
</html>