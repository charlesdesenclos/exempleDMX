<?php
    class user{
        // Variable
            private $_id;
            private $_nom;
            private $_prenom;
            private $_login;
            private $_admin;
            private $_mdp;
            private $_BDD;

        // Fonction

            // Construct
            function __construct($BDD)
            {
                $this->_BDD = $BDD;
            }

        // Fonction qui permet de collecter tout les informations d'un user 
            function getuser($id)
            {
                $request = $this->_BDD->query("SELECT * FROM `user` WHERE `id`='$id'");
                $data = $request->fetch();
                $this->_id = $data['id'];
                $this->_nom = $data['nom'];
                $this->_prenom = $data['prenom'];
                $this->_login = $data['pseudo'];
                $this->_admin = $data['admin'];
                $this->_mdp = $data['mdp'];
            }

        // Fonction qui permet au user de se connecter, elle attend en paramétre un login et un mdp
            function connexion($login, $mdp)
            {
                $requser = $this->_BDD->prepare("SELECT * FROM `user` WHERE `pseudo`=? AND `mdp`=?");
                $requser->execute(array($login, $mdp));
                $userexist = $requser->rowCount();
                if ($userexist == 1) {
                    $data = $requser->fetch();
                    $_SESSION['id'] = $data['id'];
                    $this->_id = $data['id'];
                    $this->_nom = $data['nom'];
                    $this->_prenom = $data['prenom'];
                    $this->_login = $data['pseudo'];
                    $this->_mdp = $data['mdp'];
                    $this->_admin = $data['admin'];
                    //echo '<meta http-equiv="refresh" content="0">';
                } else {
                    return "Mots de passe incorrect.";
                }
            }

        // Fonction qui permet d'update un user elle attend en paramètre un login, un mdp, un nom et un prénom
            function updateUser($login, $mdp, $nom, $prenom, $confmdp, $admin)
            {
                $requeteuser = $this->_BDD->prepare("SELECT * FROM user WHERE pseudo=?");
                $requeteuser->execute(array($login));
                $userExist = $requeteuser->rowCount();
                if ($userExist != 1) {
                    if ($mdp == $confmdp) {
                        $req = "UPDATE `user` SET `nom`='$nom',`prenom`='$prenom',`pseudo`='$login',`mdp`='$mdp',`admin` ='$admin' WHERE id='$this->_id'";
                        $this->_BDD->query($req);
                        header("Location:admin.php");
                        return "modification réussite.";
                    } else {
                        return "Le Mots de passe n'est pas le même.";
                    }
                } else if ($this->_login == $login) {
                    if ($mdp == $confmdp) {
                        $req = "UPDATE `user` SET `nom`='$nom',`prenom`='$prenom',`mdp`='$mdp',`admin` ='$admin' WHERE id='$this->_id'";
                        $this->_BDD->query($req);
                        header("Location:admin.php");
                        return "Modification réussite.";
                    } else {
                        return "Le Mots de passe n'est pas le même.";
                    }
                } else {
                    return "Se login est déja utiliser par une autre personne.";
                }
            }

        // Fonction qui permet au user de se déconnecter
            function deconnexion()
            {
                session_destroy(); // on détruit la
                header('Location:index.php'); // On redirige
            }

        // Fonction qui permet au user de s'inscrire, elle attend en commentaire un login, un mdp, un nom et un prénom
            function inscription($login, $mdp, $nom, $prenom, $confmdp)
            {
                $requeteuser = $this->_BDD->prepare("SELECT * FROM user WHERE pseudo=?");
                $requeteuser->execute(array($login));
                $userExist = $requeteuser->rowCount();
                if ($userExist != 1) {
                    if ($mdp == $confmdp) {
                        $req = "INSERT INTO `user`(`nom`, `prenom`, `pseudo`, `mdp`) VALUES ('$nom', '$prenom', '$login', '$mdp')";
                        $this->_BDD->query($req);
                        return "Inscription réussite.";
                    } else {
                        return "Le Mots de passe n'est pas le même.";
                    }
                } else {
                    return "Ce login est déjà utilisé par une autre personne.";
                }
            }

        // Fonction qui récupére tout les user en base pour la page admin
            function giveuser()
            {
                $request = $this->_BDD->query("SELECT * FROM user WHERE 1");
                while ($data = $request->fetch()) {
                    $modf = "modificationuser.php?modf=" . $data["id"];
                    $supr = "admin.php?supr=" . $data["id"];
                ?>
                    <tr>
                        <td><?= $data['id'] ?></td>
                        <td>
                            <a href="#"><?= $data['nom'] ?></a>
                        </td>
                        <td><?= $data['prenom'] ?></td>
                        <td><?= $data['pseudo'] ?></td>
                        <td><?= $data['mdp'] ?></td>
                        <?php
                        if ($data['admin'] == 1) { ?>
                            <td>Admin</td>
                        <?php } else { ?>
                            <td>User</td>
                        <?php } ?>
                        <td>
                            <a href="<?= $modf ?>" class="settings" title="modifier" data-toggle="tooltip"><img src="image/engrenage.png" alt="" srcset=""></a>
                            <a href="<?= $supr ?>" class="delete" title="supprimer" data-toggle="tooltip"><img src="image/croix.png" alt="" srcset=""></a>
                        </td>
                    </tr>
                <?php
                }
            }

        // Fonction qui permet de supprimer des user en base de données elle prend en paramètre l'id du user
            function removeUser($id)
            {
                $this->_BDD->query("DELETE FROM `user` WHERE `id`='$id'");
            }

        // Foncion qui return le nom du user
            function getnom()
            {
                return $this->_nom;
            }

        // Fonction qui return le prenom du user
            function getprenom()
            {
                return $this->_prenom;
            }

        // Fonction qui return le login du user
            function getlogin()
            {
                return $this->_login;
            }

        // Fonction qui return l'id du user
            function getid()
            {
                return $this->_id;
            }

        // Fonction qui return le statue admin
            function getadmin()
            {
                return $this->_admin;
            }

        // Fonction qui return le mots de passe
            function getmdp()
            {
                return $this->_mdp;
            }
    }
?>