Rappel de mon OPC : 

- Un jeu de l'oie multijoueur avec des personnages animaux façon "Mii" dans un univers cartoon stylisé 
- Des mini-jeux entre chaque tours
- Des cases spéciales qui déclenches des mini-jeux
- Les mini-jeux peuvent être chacun pour soi, seul contre tous ou 2v2 (selon le nombre de joueurs)
- Pépin se trouve sur une case du plateau et donne une quête au joueur qui le croise avant de changer d'emplacement

Devoir POC :
  - Pour ce devoir, j'ai réalisé un memory un peu spécial : le joueur ne doit pas trouver des pairs, mais une séquence de tuiles valides pour relier un point A à un point B. Il peut retourner des tuiles tant qu'il a juste, s'il en retourne une mauvaise tout se remet à 0 et le joueur doit recommencer.
  - Le memory est consituté à 80% en c++, en génération procédurale avec un pathfinding aléatoire (sur une même grille le chemin à prendre peut être différent d'une génération à l'autre). Les animations sont également en code pur, Seul l'UI et l'input du clic sont gérés en bluprint.
  - Le jeu de plateau en lui-même est partiellement en c++, les fonctions c++ sont utilisées en blueprint pour la majorité des objets, et les autres sont en blueprint simple.

Devoir Collect :
  - Pour ce devoir, tout est 100% en c++. Le personnage doit collecter des fruits qui poussent sur les arbres afin de les ramener à son panier. Les fruit standard rapportent 10 points, les fruits dorés 50. En appuyant sur espace, le joueur peut bousculer ce qui se trouve en face de lui, ce qui permet de faire tomber les fruits des arbres, et à terme de faire tomber les fruits des autres joueurs (pour l'instant le multijoueur n'est pas implémenté). Les fruits collectés sont empilés sur le personnage jusqu'à ce qu'il les amène au panier ou qu'un autre joueur ne les fasse tomber. L'UI comprend un compteur de fruits (qui apparaît lorsque le joueur collecte son troisième fruit), un timer et un compteur de point total.
  - La collecte fonctionne grâce à un component pour le collectible, et une interface pour le collecteur. Si un objet implémentant l'interface collisionne avec le component, il gagne des points et détruit le collectible. Le retour visuel (l'empilement des fruits, l'affichage du compteur etc...) se gère directement dans les classes qui implémentent l'interface / le component.

Les choses que j'aimerais rajouter :
  - Le mutijoueur dans chaque minijeu
  - La possibilité de rajouter des IA
  - Pépin qui donne des objectifs secondaires au/x joueur/s
  - Pour l'instant les minijeux sont solo. Je voudrais rajouter des minijeux en équipe.
  - Choix de personnage

Mot sur le projet c++ :
J'ai été particulièrement content de faire ce projet, je me suis rajouté la contrainte de faire 100% c++ pour le mini jeu de collecte ce qui m'a permis de comprendre plein de chose et de prendre énormément de plaisir, j'ai presque eu l'impression de réapprendre Unreal. Le blueprint est l'une des raisons principales pour lesquelles je n'aime pas unreal, pour plein de raison, mais là j'ai tellement aimé le développement c++ que j'aimerais à l'avenir en faire par défaut dans mes projets unreal, juste par plaisir. Une fois le problème du lien unreal<--->IDE passé, ça devient très libérateur.
