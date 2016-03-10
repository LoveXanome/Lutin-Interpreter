Programme de tests automatiques - mode d'emploi

Auteur : Eric Guérin

Change log :
- 0.1 (2013/11/4)
- 0.2 (2013/11/15). Ajout fonctionnalité test flux erreur standard
- 0.3 (2013/11/20). Formattage de la description sur 60 colonnes (fold)

-------------------------------------------------------------------------------
test.sh [ repertoire [ fichier.csv ] ]

- repertoire indique le répertoire dans lequel se trouvent les fichiers de 
configuration du test
- fichier.csv indique un fichier dans lequel les résultats du tests seront 
ajoutés

En l'absence d'arguments, le script traitera le répertoire courant

Fichiers de configuration :
- run : fichier texte indiquant la ligne de commande à éxécuter (obligatoire)
- std.in : fichier texte indiquant une entrée clavier à simuler (facultatif)
- std.out : fichier texte indiquant la sortie devant être produite 
(facultatif/validation*)
- stderr.out : fichier texte indiquant la sortie d'erreur devant être produite 
(facultatif/validation*)
- description : fichier texte donnant la description du test (facultatif)
- returncode : fichier texte contenant l'entier code retour attendu 
(facultatif/validation*)
- *.outfile : un ou plusieurs fichiers devant être produits par le programme 
(facultatif/validation*)
  si le fichier s'appelle exemple.txt.outfile, il sera comparé à exemple.txt

*validation indique que le script va tester la conformité, si cette conformité 
n'est pas 
satisfaite, il l'indiquera

-------------------------------------------------------------------------------
mktest.sh

Fichier à personnaliser. Dans l'état, il cherche à valider tous les tests 
contenus dans les répertoires dont le nom correspond à ??.*
