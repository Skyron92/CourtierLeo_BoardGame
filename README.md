Rappel de mon OPC : 

- Un jeu de l'oie multijoueur avec des personnages animaux façon "Mii" dans un univers cartoon stylisé 
- Des mini-jeux entre chaque tours
- Des cases spéciales qui déclenches des mini-jeux
- Les mini-jeux peuvent être chacun pour soi, seul contre tous ou 2v2 (selon le nombre de joueurs)
- Pépin se trouve sur une case du plateau et donne une quête au joueur qui le croise avant de changer d'emplacement

Dans cette itération du projet :
  - Le jeu est jouable à 2, 3 ou 4 joueurs.
  - Lorsqu'un pion tombe sur une case occupée par un joueur, il le saute et passe à la case suivante, ce qui permet au dernier joueur d'avoir plus de chance d'avoir une case bonus que le premier.
  - Si un joueur fait plus de déplacement que nécessaire pour atteindre l'arrivée, il s'arrête dessus. Je tiens à préciser que je souhaitais le faire repartir en arrière, mais j'ai rencontré un bug étrange : Dans ma fonction MovePawnByCellIndex située dans          
  Board.cpp, chaque modification faisait crash Unreal, par exemple si je crée un int, même si je le set à 0 et que je n'y touche pas, Unreal crash. De même si j'entrais la formule directement en paramètre de SetActorLocation(), comme ça n'avait aucun sens j'en ai      déduis que c'était un bug technique d'unreal et j'ai donc choisi la facilité en vue de le modifier plus tard...

Ce que j'aurais souhaité améliorer au sein même de cette itération si j'avais eu plus de temps :
  - Actuellement les joueurs contrôlent tous des pingouins de couleurs différentes. Les couleurs sont prédéfinies et ont un rôle purement fonctionnel. J'aimerais donc que le joueur choisisse sa couleur lui-même, et dans une prochaine itération, qu'il puisse choisir    d'autres animaux.
  - Lorsqu'on lance le dé, le résultat s'affiche sur une image. J'aimerais créer un peu de suspense en lançant une animation de défilement aléatoire à la manière d'une machine à sou avant de dévoiler le résultat du dé.
