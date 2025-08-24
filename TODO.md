# TODO:

<!-- - Musique ? -->
- Appliquer au mieux les concepts vus au cours: SINGLETON, HÉRITAGE, ETC... (voir cours et slides)
<!-- - Faire fonctionner le refactoring utilisant le modèle MVC -->
- Fichier qui retient les scores (selon les niveaux ?) et qui update à chaque game
<!-- - Passer le model complet à la view ou juste les éléments indépendamment ? View singleton statique ? Ou sorcellerie malicieuse ? -->
<!-- - Faire une classe parente à tous les objets qui contiendrait: les couleurs de l'objet, des getters des setters. -->
- Bien double check tous les commentaires, tous les types, tout le typing (encore des cas de snake/duck typing mélangés présents). Pour les getters et setters essayer d'ajouter au max const et noexcept, question de propreté.
- Placer tous les calculs de top/bottom/left/right en tant que méthode interne de l'objet pour éviter de se retaper le calcul en boucle
- casser brique -> power up drop (ajouter au modèle) -> power up tombe (update modèle avec l'engine) -> contact avec la raquette
- Essayer de retirer les espérluettes de gueu dans les getters (logiquement un getter renvoie une réf ?)
- Retirer les shared_ptr pour les objets comme la racket, ... (ceux contenus dans les modèles) et garder des unique_ptr pour les "gros" objets