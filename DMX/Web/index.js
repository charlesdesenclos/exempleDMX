// Gestion Slide
    // Slide N°0
        var slider01 = document.getElementById("slide01");
        var output1 = document.getElementById("value01");
        output1.innerHTML = slider01.value; 
        slider01.oninput = function(){
            output1.innerHTML = this.value;
            console.log("SLIDER :: 00 :: " + slider01.value);//envoie en console les valeurs
            websocket.send("SLIDER :: 00 :: " +  slider01.value );//envoie au serveur les valeurs du slider
        }

    // Slide N°1
        var slider02 = document.getElementById("slide02");
        var output2 = document.getElementById("value02");
        output2.innerHTML = slider02.value; 
        slider02.oninput = function(){
            output2.innerHTML = this.value;
            console.log("SLIDER :: 01 :: " + slider02.value);
            websocket.send("SLIDER :: 01 :: " +  slider02.value );
        }

    // Slide N°2
        var slider03 = document.getElementById("slide03");
        var output3 = document.getElementById("value03");
        output3.innerHTML = slider03.value; 
        slider03.oninput = function(){
            output3.innerHTML = this.value;
            console.log("SLIDER :: 02 :: " + slider03.value);
            websocket.send("SLIDER :: 02 :: " + slider03.value );
        }

    // Slide N°3
        var slider04 = document.getElementById("slide04");
        var output4 = document.getElementById("value04");
        output4.innerHTML = slider04.value; 
        slider04.oninput = function(){
            output4.innerHTML = this.value;
            console.log("SLIDER :: 03 :: " + slider04.value);
            websocket.send("SLIDER :: 03 :: " + slider04.value );
        }

    // Slide N°4
        var slider05 = document.getElementById("slide05");
        var output5 = document.getElementById("value05");
        output5.innerHTML = slider05.value; 
        slider05.oninput = function(){
            output5.innerHTML = this.value;
            console.log("SLIDER :: 04 :: " + slider05.value);
            websocket.send("SLIDER :: 04 :: " + slider05.value );
        }

    // Slide N°5
        var slider06 = document.getElementById("slide06");
        var output6 = document.getElementById("value06");
        output6.innerHTML = slider06.value; 
        slider06.oninput = function(){
            output6.innerHTML = this.value;
            console.log("SLIDER :: 05 :: " + slider06.value);
            websocket.send("SLIDER :: 05 :: " + slider06.value );

        }

    // Slide N°6
        var slider07 = document.getElementById("slide07");
        var output7 = document.getElementById("value07");
        output7.innerHTML = slider07.value; 
        slider07.oninput = function(){
            output7.innerHTML = this.value;
            console.log("SLIDER :: 06 :: " + slider07.value);
            websocket.send("SLIDER :: 06 :: " + slider07.value );
        }

    // Slide N°7
        var slider08 = document.getElementById("slide08");
        var output8 = document.getElementById("value08");
        output8.innerHTML = slider08.value; 
        slider08.oninput = function(){
            output8.innerHTML = this.value;
            console.log("SLIDER :: 07 :: " + slider08.value);
            websocket.send("SLIDER :: 07 :: " + slider08.value );
        }

    // Slide N°8
        var slider09 = document.getElementById("slide09");
        var output9 = document.getElementById("value09");
        output9.innerHTML = slider09.value; 
        slider09.oninput = function(){
            output9.innerHTML = this.value;
            console.log("SLIDER :: 08 :: " + slider09.value);
            websocket.send("SLIDER :: 08 :: " + slider09.value );
        }

    // Slide N°9
        var slider10 = document.getElementById("slide10");
        var output10 = document.getElementById("value10");
        output10.innerHTML = slider10.value; 
        slider10.oninput = function(){
            output10.innerHTML = this.value;
            console.log("SLIDER :: 09 :: " + slider10.value);
            websocket.send("SLIDER :: 09 :: " + slider10.value );
        }

    // Slide N°10
        var slider11 = document.getElementById("slide11");
        var output11 = document.getElementById("value11");
        output11.innerHTML = slider11.value; 
        slider11.oninput = function(){
            output11.innerHTML = this.value;
            console.log("SLIDER :: 10 :: " + slider11.value);
            websocket.send("SLIDER :: 10 :: " + slider11.value );
        }

    // Slide N°11
        var slider12 = document.getElementById("slide12");
        var output12 = document.getElementById("value12");
        output12.innerHTML = slider12.value; 
        slider12.oninput = function(){
            output12.innerHTML = this.value;
            console.log("SLIDER :: 11 :: " + slider12.value);
            websocket.send("SLIDER :: 11 :: " + slider12.value );
        }

    // Bouton Reset
        var FranceButton = document.getElementsByClassName("FranceButton")[0];
        FranceButton.addEventListener('click',function() 
        {
            output3.innerHTML=slider03.value=255 // Bleu  Lampe 1
            output8.innerHTML=slider08.value=255 // Blanc Lampe 2
            output9.innerHTML=slider09.value=255 // Rouge Lampe 3

            websocket.send("ALLUME FRANCE");
            console.log('ALLUME FRANCE');
        })
        
    // Bouton Reset
        var ButtonReset = document.getElementsByClassName("OffAllButton")[0];
        ButtonReset.addEventListener('click',function() 
        {
            output1.innerHTML=slider01.value=0 // Rouge Lampe 1
            output2.innerHTML=slider02.value=0 // Vert  Lampe 1
            output3.innerHTML=slider03.value=0 // Bleu  Lampe 1
            output4.innerHTML=slider04.value=0 // Blanc Lampe 1

            output5.innerHTML=slider05.value=0 // Rouge Lampe 2
            output6.innerHTML=slider06.value=0 // Vert  Lampe 2
            output7.innerHTML=slider07.value=0 // Bleu  Lampe 2
            output8.innerHTML=slider08.value=0 // Blanc Lampe 2

            output9.innerHTML=slider09.value=0 // Rouge Lampe 3
            output10.innerHTML=slider10.value=0// Vert  Lampe 3
            output11.innerHTML=slider11.value=0// Bleu  Lampe 3
            output12.innerHTML=slider12.value=0// Blanc Lampe 3

            websocket.send("RESET ALL");
            console.log('RESET ALL');
        })

    // Bouton OnAllButton
        var ButtonReset = document.getElementsByClassName("OnAllButton")[0];
        ButtonReset.addEventListener('click',function() 
        {
            output1.innerHTML=slider01.value=255 // Rouge Lampe 1
            output2.innerHTML=slider02.value=255 // Vert  Lampe 1
            output3.innerHTML=slider03.value=255 // Bleu  Lampe 1
            output4.innerHTML=slider04.value=255 // Blanc Lampe 1

            output5.innerHTML=slider05.value=255 // Rouge Lampe 2
            output6.innerHTML=slider06.value=255 // Vert  Lampe 2
            output7.innerHTML=slider07.value=255 // Bleu  Lampe 2
            output8.innerHTML=slider08.value=255 // Blanc Lampe 2

            output9.innerHTML=slider09.value=255 // Rouge Lampe 3
            output10.innerHTML=slider10.value=255// Vert  Lampe 3
            output11.innerHTML=slider11.value=255// Bleu  Lampe 3
            output12.innerHTML=slider12.value=255// Blanc Lampe 3

            websocket.send("ALLUME ALL");
            console.log('ALLUME ALL');
        })

    // Reset Lampe 1
        var ButtonReset = document.getElementsByClassName("ResetLampe1")[0];
        ButtonReset.addEventListener('click',function() 
        {
            output1.innerHTML=slider01.value=0 // Rouge Lampe 1
            output2.innerHTML=slider02.value=0 // Vert  Lampe 1
            output3.innerHTML=slider03.value=0 // Bleu  Lampe 1
            output4.innerHTML=slider04.value=0 // Blanc Lampe 1

            websocket.send("RESET LAMPE 1");
            console.log('RESET LAMPE 1');
        })

    // Reset Lampe 2
        var ButtonReset = document.getElementsByClassName("ResetLampe2")[0];
        ButtonReset.addEventListener('click',function() 
        {
            output5.innerHTML=slider05.value=0 // Rouge Lampe 2
            output6.innerHTML=slider06.value=0 // Vert  Lampe 2
            output7.innerHTML=slider07.value=0 // Bleu  Lampe 2
            output8.innerHTML=slider08.value=0 // Blanc Lampe 2

            websocket.send("RESET LAMPE 2");
            console.log('RESET LAMPE 2');
        })

    // Reset Lampe 3
        var ButtonReset = document.getElementsByClassName("ResetLampe3")[0];
        ButtonReset.addEventListener('click',function() 
        {
            output9.innerHTML=slider09.value=0 // Rouge Lampe 3
            output10.innerHTML=slider10.value=0// Vert  Lampe 3
            output11.innerHTML=slider11.value=0// Bleu  Lampe 3
            output12.innerHTML=slider12.value=0// Blanc Lampe 3

            websocket.send("RESET LAMPE 3");
            console.log('RESET LAMPE 3');
        })


    // ALLUME Lampe 1
        var ButtonAllume = document.getElementsByClassName("AllumeLampe1")[0];
        ButtonAllume.addEventListener('click',function() 
        {
            output1.innerHTML=slider01.value=255 // Rouge Lampe 1
            output2.innerHTML=slider02.value=255 // Vert  Lampe 1
            output3.innerHTML=slider03.value=255 // Bleu  Lampe 1
            output4.innerHTML=slider04.value=255 // Blanc Lampe 1

            websocket.send("ALLUME LAMPE 1");
            console.log('ALLUME LAMPE 1');
        })

    // ALLUME Lampe 2
        var ButtonAllume = document.getElementsByClassName("AllumeLampe2")[0];
        ButtonAllume.addEventListener('click',function() 
        {
            output5.innerHTML=slider05.value=255 // Rouge Lampe 2
            output6.innerHTML=slider06.value=255 // Vert  Lampe 2
            output7.innerHTML=slider07.value=255 // Bleu  Lampe 2
            output8.innerHTML=slider08.value=255 // Blanc Lampe 2

            websocket.send("ALLUME LAMPE 2");
            console.log('ALLUME LAMPE 2');
        })

    // ALLUME Lampe 3
        var ButtonAllume = document.getElementsByClassName("AllumeLampe3")[0];
        ButtonAllume.addEventListener('click',function() 
        {
            output9.innerHTML=slider09.value=255 // Rouge Lampe 3
            output10.innerHTML=slider10.value=255// Vert  Lampe 3
            output11.innerHTML=slider11.value=255// Bleu  Lampe 3
            output12.innerHTML=slider12.value=255// Blanc Lampe 3

            websocket.send("ALLUME LAMPE 3");
            console.log('ALLUME LAMPE 3');
        })

    // ALLUME COLOR ROUGE
        var ButtonAllume = document.getElementsByClassName("AllumeRouge")[0];
        ButtonAllume.addEventListener('click',function() 
        {
            output1.innerHTML=slider01.value=255 // Rouge Lampe 1
            output5.innerHTML=slider05.value=255 // Rouge Lampe 2
            output9.innerHTML=slider09.value=255 // Rouge Lampe 3

            websocket.send("ALLUME COLOR ROUGE");
            console.log('ALLUME COLOR ROUGE');
        })

    // ALLUME COLOR VERT
        var ButtonAllume = document.getElementsByClassName("AllumeVert")[0];
        ButtonAllume.addEventListener('click',function() 
        {
            output2.innerHTML=slider02.value=255 // Vert  Lampe 1
            output6.innerHTML=slider06.value=255 // Vert  Lampe 2
            output10.innerHTML=slider10.value=255// Vert  Lampe 3

            websocket.send("ALLUME COLOR VERT");
            console.log('ALLUME COLOR VERT');
        })

    // ALLUME COLOR BLEU
        var ButtonAllume = document.getElementsByClassName("AllumeBleu")[0];
        ButtonAllume.addEventListener('click',function() 
        {
            output3.innerHTML=slider03.value=255 // Bleu  Lampe 1
            output7.innerHTML=slider07.value=255 // Bleu  Lampe 2
            output11.innerHTML=slider11.value=255// Bleu  Lampe 3

            websocket.send("ALLUME COLOR BLEU");
            console.log('ALLUME COLOR BLEU');
        })

    // ALLUME COLOR BLANC
        var ButtonAllume = document.getElementsByClassName("AllumeBlanc")[0];
        ButtonAllume.addEventListener('click',function() 
        {
            output4.innerHTML=slider04.value=255 // Blanc Lampe 1
            output8.innerHTML=slider08.value=255 // Blanc Lampe 2
            output12.innerHTML=slider12.value=255// Blanc Lampe 3

            websocket.send("ALLUME COLOR BLANC");
            console.log('ALLUME COLOR BLANC');
        })

    // RESET COLOR ROUGE
        var ButtonReset = document.getElementsByClassName("ResetRouge")[0];
        ButtonReset.addEventListener('click',function() 
        {
            output1.innerHTML=slider01.value=0 // Rouge Lampe 1
            output5.innerHTML=slider05.value=0 // Rouge Lampe 2
            output9.innerHTML=slider09.value=0 // Rouge Lampe 3

            websocket.send("RESET COLOR ROUGE");
            console.log('RESET COLOR ROUGE');
        })

    // RESET COLOR VERT
        var ButtonReset = document.getElementsByClassName("ResetVert")[0];
        ButtonReset.addEventListener('click',function() 
        {
            output2.innerHTML=slider02.value=0 // Vert  Lampe 1
            output6.innerHTML=slider06.value=0 // Vert  Lampe 2
            output10.innerHTML=slider10.value=0// Vert  Lampe 3

            websocket.send("RESET COLOR VERT");
            console.log('RESET COLOR VERT');
        })

    // RESET COLOR BLEU
        var ButtonReset = document.getElementsByClassName("ResetBleu")[0];
        ButtonReset.addEventListener('click',function() 
        {
            output3.innerHTML=slider03.value=0 // Bleu  Lampe 1
            output7.innerHTML=slider07.value=0 // Bleu  Lampe 2
            output11.innerHTML=slider11.value=0// Bleu  Lampe 3

            websocket.send("RESET COLOR BLEU");
            console.log('RESET COLOR BLEU');
        })

    // RESET COLOR BLANC
        var ButtonReset = document.getElementsByClassName("ResetBlanc")[0];
        ButtonReset.addEventListener('click',function() 
        {
            output4.innerHTML=slider04.value=0 // Blanc Lampe 1
            output8.innerHTML=slider08.value=0 // Blanc Lampe 2
            output12.innerHTML=slider12.value=0// Blanc Lampe 3

            websocket.send("RESET COLOR BLANC");
            console.log('RESET COLOR BLANC');
        })

    // START RAND
        var ButtonReset = document.getElementsByClassName("StartRandom")[0];
        ButtonReset.addEventListener('click',function() 
        {
            output1.innerHTML=slider01.value=255 // Rouge Lampe 1
            output2.innerHTML=slider02.value=255 // Vert  Lampe 1
            output3.innerHTML=slider03.value=255 // Bleu  Lampe 1
            output4.innerHTML=slider04.value=255 // Blanc Lampe 1
            output5.innerHTML=slider05.value=255 // Rouge Lampe 2
            output6.innerHTML=slider06.value=255 // Vert  Lampe 2
            output7.innerHTML=slider07.value=255 // Bleu  Lampe 2
            output8.innerHTML=slider08.value=255 // Blanc Lampe 2
            output9.innerHTML=slider09.value=255 // Rouge Lampe 3
            output10.innerHTML=slider10.value=255// Vert  Lampe 3
            output11.innerHTML=slider11.value=255// Bleu  Lampe 3
            output12.innerHTML=slider12.value=255// Blanc Lampe 3

            websocket.send("RANDOM START");
            console.log('RANDOM START');
        })

    // STOP RAND
        var ButtonReset = document.getElementsByClassName("StopRandom")[0];
        ButtonReset.addEventListener('click',function() 
        {
            output1.innerHTML=slider01.value=0 // Rouge Lampe 1
            output2.innerHTML=slider02.value=0 // Vert  Lampe 1
            output3.innerHTML=slider03.value=0 // Bleu  Lampe 1
            output4.innerHTML=slider04.value=0 // Blanc Lampe 1
            output5.innerHTML=slider05.value=0 // Rouge Lampe 2
            output6.innerHTML=slider06.value=0 // Vert  Lampe 2
            output7.innerHTML=slider07.value=0 // Bleu  Lampe 2
            output8.innerHTML=slider08.value=0 // Blanc Lampe 2
            output9.innerHTML=slider09.value=0 // Rouge Lampe 3
            output10.innerHTML=slider10.value=0// Vert  Lampe 3
            output11.innerHTML=slider11.value=0// Bleu  Lampe 3
            output12.innerHTML=slider12.value=0// Blanc Lampe 3

            websocket.send("RANDOM STOP");
            console.log('RANDOM STOP');
        })