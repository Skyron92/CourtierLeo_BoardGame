Rappel de mon OPC : 
======================================================================================================
- Un jeu de l'oie multijoueur avec des personnages animaux façon "Mii" dans un univers cartoon stylisé 
- Des mini-jeux entre chaque tours
- Des cases spéciales qui déclenches des mini-jeux
- Les mini-jeux peuvent être chacun pour soi, seul contre tous ou 2v2 (selon le nombre de joueurs)
- Pépin se trouve sur une case du plateau et donne une quête au joueur qui le croise avant de changer d'emplacement

Devoir POC :
======================================================================================================
  - Pour ce devoir, j'ai réalisé un memory un peu spécial : le joueur ne doit pas trouver des pairs, mais une séquence de tuiles valides pour relier un point A à un point B. Il peut retourner des tuiles tant qu'il a juste, s'il en retourne une mauvaise tout se remet à 0 et le joueur doit recommencer.
  - Le memory est consituté à 80% en c++, en génération procédurale avec un pathfinding aléatoire (sur une même grille le chemin à prendre peut être différent d'une génération à l'autre). Les animations sont également en code pur, Seul l'UI et l'input du clic sont gérés en bluprint.
  - Le jeu de plateau en lui-même est partiellement en c++, les fonctions c++ sont utilisées en blueprint pour la majorité des objets, et les autres sont en blueprint simple.

Problèmes connus :
--------------------------------------------
  - Il n'y a pas d'animation sur les personnages. La raison est que mes personnages sont spéciaux et que je ne pouvais donc pas me contenter d'importer une animation mixamo. Par manque de temps, j'ai donc choisi de privilégier ce que je ne savais pas faire, à savoir le c++. J'ai commencé le code d'animation idle (codé dans le c++ du character) mais je n'ai pas eu le temps de le mettre au point. (Je compte le faire par la suite, mais pas dans le cadre du devoir du coup)
  - Les personnages ne se déplacent pas de case en case mais se téléportent (la raison ici est que je compte faire une animation procédurale très simple faisant bondir les personnages de case en case, ce qui ramène au problème précédent)

Les choses que j'aimerais rajouter :
--------------------------------------------
  - Animations
  - Le mutijoueur dans chaque minijeu
  - La possibilité de rajouter des IA
  - Pépin qui donne des objectifs secondaires au/x joueur/s
  - Pour l'instant les minijeux sont solo. Je voudrais rajouter des minijeux en équipe.
  - Choix de personnage

Devoir Collect :
======================================================================================================
Pour tester le projet, il faut simplement ouvrir le level Content/Level/MiniGameCollect. Concernant le code, toutes les classes c++ liées à ce minijeu sont dans un dossier "CollectMinigame". Les blueprints qui en héritent se trouve dans Content\Blueprints\Minigames\Collect.

Information sur le projet :
--------------------------------------------
  - Pour ce devoir, tout est 100% en c++. Le personnage doit collecter des fruits qui poussent sur les arbres afin de les ramener à son panier. Les fruit standard rapportent 10 points, les fruits dorés 50.
  - Les fruits spawnent aléatoirement sur les arbres, les fruits dorés ont 10% de chance d'aparaître.
  - Le jeu se joue en ZQSD. En appuyant sur espace, le joueur peut bousculer ce qui se trouve en face de lui, ce qui permet de faire tomber les fruits des arbres, et à terme de faire tomber les fruits des autres joueurs (pour l'instant le multijoueur n'est pas implémenté).
  - Les fruits collectés sont empilés sur le personnage jusqu'à ce qu'il les amène au panier ou qu'un autre joueur ne les fasse tomber. L'UI comprend un compteur de fruits (qui apparaît lorsque le joueur collecte son troisième fruit), un timer et un compteur de point total.
  - La collecte fonctionne grâce à un component pour le collectible, et une interface pour le collecteur. Si un objet implémentant l'interface collisionne avec le component, il gagne des points et détruit le collectible. Le retour visuel (l'empilement des fruits, l'affichage du compteur etc...) se gère directement dans les classes qui implémentent l'interface / le component.

Bugs connus :
--------------------------------------------
  - Le compteur de fruit du joueur affiche toujours 10 lors de sa première appararition, et ne s'actualise pas. Dès la seconde apparition il n'y a plus de problème.
  - De temps en temps, un arbre ne spawn aucun fruit durant toute la partie.
  - L'UI de fin (avec le bouton continue) ramène au jeu de plateau, mais cela recommence une partie. (Ce n'est pas vraiment un bug je n'ai juste pas eu le temps de gérer cela)

Les choses que j'aimerais rajouter :
--------------------------------------------
  - Du visuel pour le joueur et le panier
  - Améliorer l'UI, trop chargé actuellement

Mot sur le projet c++ :
======================================================================================================
J'ai été particulièrement content de faire ce projet, je me suis rajouté la contrainte de faire 100% c++ pour le mini jeu de collecte ce qui m'a permis de comprendre plein de chose et de prendre énormément de plaisir, j'ai presque eu l'impression de réapprendre Unreal. Le blueprint est l'une des raisons principales pour lesquelles je n'aime pas unreal, pour plein de raison, mais là j'ai tellement aimé le développement c++ que j'aimerais à l'avenir en faire par défaut dans mes projets unreal, juste par plaisir (évidemment il sera sage de rester souple entre blueprint en c++ dans de vrais projets). Une fois le problème du lien unreal<--->IDE passé, ça devient très libérateur. Je voulais donc te remercier pour ces cours qui m'ont personnellement beaucoup apporté !
