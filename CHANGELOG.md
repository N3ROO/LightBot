## DEV CHANGELOG ##
+ : Add
* : Fix, improved
- : Removed
& : To do
$ : New bug

## Version 1: 24/04/17 ##
+ Button class
+ Application class (motehr of Interface)
+ Cell 
+ Grid (Still hexagones calculations to do)
+ Theme
+ Utils
$ Apply label to window makes an unknow crash

## Version 2: 24/04/17 ##
+ Grid working

## Version 3: 24/04/17 ##
+ Cell light color

## Version 4: 25/04/17 ##
* Font fix
$ Memomry (deleting buttons - check issues)

## Version 5: 25/04/17 ##
* Memory cleaning fix

## Version 6: 25/04/17 ##
* Button update fix
* Output added

## Version 7: 25/04/17 ##
* Button class ready for the actions
* Cleaned the entiere code
* Commented the entiere code
* Fixed warnings

## Version 8: 25/04/17 ##
* Label added in the Theme
+ Background methods added
* Theme improved (label placement & appareance)

## Version 9 : 05/05/17 ##
* Button's constructor now takes its label
* New font fix (it was a pointer / reference problem)
* Changed ressources to resources

## Version 10 : 05/05/17 ##
+ loadLevel : it loads a level from a file 
	- it doesn't cause a crash if the level does not exist)
	- it overrides the precedent level if there was one
	- levels ready for next updates
* Fixed grid conception problems (some crashes)

## Version 11 : 09/05/17 ##
+ saveLevel()  
+ level selection working

## Version 12 : 10/05/17 ##
* Changed level id from int to string (problem 00 != 0)
* Fixed showGrid algorithm
* Fixed memory loose

## Version 13 : 15/05/17 ##
* Fixed labels (bob fix)
+ Added an attribute for the mouse status : m_pressing_mouse (application.h)
+ Constructor by copy for button to move it: draw_button_at(..)
+ Rectangle moving
+ Added programbox

## Version 14 : 16/05/17 ##
+ Implementation des programboxes (non fini)

## Version 15: 19/05/17 ##
+ Ajout des textures des boutons
+ Ajout du robot
+ Ajout de program handler
* Fix textures
+ et plein d'autres choses..........

## Version 16: 22/05/17 ##
+ Ajout des deux prgm box (p1, p2)
* Résolution des warnings
* Résolutions des fuites mémoire
* Résolution du problème avec le texte ds prgm box
* Préparation pour la mise à jour de program handler

## Version 17 : 22/05/17 ##
======= MAJOR UPDATE =======
* Changement du robot par une image
* Amélioration visuelle
* Résolution save level en ajoutant les infos du robot
* Changement des coordonnées dans la grille par leur hauteur
+ Finition du runProgram()
+ Implem delete action (row) et auto-alignement des boutons
+ Implet insertion action
+ ..... PLEIN DE CHOSES

## Version 18 : 23/05/17 ##
* Fix delete action
+ Debut ajout end screen
* Fix saut

## Version 19 : 23/05/17 ##
==== VERSION BUGUEE (normal)

.. Continuation (lol) de l'écran de fin d'execution

## Version 20 : 28/05/17 ##
+ Execution pas à pas avec indications
+ End screen avec messages

## Version 21 : 28/05/17 ##
+ Visuel saut
* Fix crash si on utilise pas P1 et/ou P2

## Verson 22 : 29/05/17 ##
* Fix qqes problèmes de chargement de police (grid)
* Qqes autres fix
+ positionToPixels()
+ début commentaire
* clean code

## Version 23 : 29/05/17 ##
* Fix bugs de couleurs quand on perd dans P1 et/ou P2
* Fin commentaires
* Plein de petits fix
* Améliorations de l'algo d'execution

## Version 24 : 30/05/17 ##
+ Level validity checker
+ Level name display

## Version 25 : 30/05/17 ##
* Fixed a critical crash with out of range exception if p1 & p2 have action but main have not p1 &&/|| p2

