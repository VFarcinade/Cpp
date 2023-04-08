Contenu:_main.cpp
	_MakeFile
	_readme.txt

	//dossier incldude
	_mat.hpp
	_vec.hpp
	_vec.cpp

	//dossier src
	_mat.cpp
	_op_mat.cpp
	_squared_solver.cpp
	_ms_solver.cpp



/!\ Codant sous windows (et oui..) j'ai du modifier le makefile que l'on nous a fournit en TP
pour que cela fonctionne. Ici j'ai remis le makefile initiale mais je n'ais pas pu  le tester avec mon pc. Th�oriquement il fonctionne car j'ai gard� la m�me arborescence, mais je pr�f�rais pr�venir.

1/
main.cpp: fichier test:	-test du solver pour probl�me avec matrices carr�es (sur une laplacienne)
			-test des 3 solveurs du pb de moindre carr�s sur un probl�me qui admet une solution exact (que l'on a nous m�me construit. On s'attend donc � un r�sidu nul

			-test des 3 solveurs sur un pb al�atoire. On s'attend donc � ce que les 3 solveurs renvoient le m�me r�sultat

			_test des temps de r�solutions des 3 m�thodes, on effectue une moyenne sur n matrices al�atoires (on r�cup�re �galement la variance pour v�rifier que la machine n'a pas eu de grosses perturbations). On peut voir que sur ce type de probl�me, la m�thode de l��quation normale semble la plus rapide

			_test de la croissance du r�sidu en fonction des valeurs de N et M. A M fix�, une augmentation de N entra�ne une augmentation du r�sidu. A N fix�, une augmentation de M jusqu'� N-1, entra�ne une r�duction du r�sidu (on se rapproche d'un probl�me carr�




2/vec.hpp & vec.cpp: comme nous sommes amen�s � utiliser des objets de type vector tout au long du projet, nous avons r�uni ici toutes les fonctions dont nous avons eu besoin (qui concerne uniquement les vecteurs et non les matrices).
On y a impl�ment�:	_la somme et la diff�rence de deux vecteurs 
			_le produit par un scalaire et par son inverse 
			_la norme 2 et le produit scalaire
			_une fonction d'affichage
			_un calcul de la moy et var du contenu d'un vecteur




3/mat.hpp & (mat.cpp, op_mat.cpp, squared_solver.cpp et mc_solver.cpp): classe mat: repr�sente des matrices des taille n*m

_3 constructeurs:	_on initialise les param�tres de taille (0x0 par d�fauts)
			_par copie
			_on initialise la taille de la matrice et on la remplie al�atoirement (loi normal(0,1))

_3 surcharges d�op�rateurs classiques�: 			
		_�galit�: =
		_affichage: <<
		_test d'�galit�: == (pr�cision 10^-5)

_diverses fonctions dont on se sert tout le long du programme :
		_Load : charge une matrice � partir d'un fichier qui respect la syntaxe impos�e
		_Laplace : transforme une matrice en laplacienne
		_Identity: transforme une matrice en l'identit�
		_resize: change le format de la matrice
		_nb_elem: renvoie le nombre de coefficient de la matrice
		_permute: permute deux colonnes d'une matrice
		_trans: transforme la seconde matrice en la transpos� de la premi�re
		_extract_col: renvoie un vecteur contenant la colonne j d'une matrice

_accesseur et mutateurs : row,col et op�rateurs () pour les coefficients (les deux versions sont disponibles pour chacune)

_fonction d'op�rations: _produit matrice/vecteurs et vecteurs/matrice 
			_produit matrice/matrice 
			_produit matrice householder (� partir d'un vecteur) / matrice quelconque
			_produit matrice quelconque / matrice householder(� partir d'un vecteur)


_fonction solvers:	_solveur d'un syst�me triangulaire sup quelconque et d'un syst�me triangulaire inf � diag unit�
			_solveur d'un syst�me avec matrice carr� inversible et fonction de d�composition LU
			_solveur de eq normale, gramschmidt et householder
			_res: calcul du r�sidu 

						