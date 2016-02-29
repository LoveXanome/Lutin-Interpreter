/*
 * Etat.hpp
 * 
 * Copyright 2016 Bulme Kevin <kbulme@if501-219-15.insa-lyon.fr> Mas Kevin
 * 
 */
#ifndef ETAT.HPP
#define ETAT.HPP


class Etat {
	public :
		Etat(string name);
		virtual ~Etat();
		void print() const;
		virtual bool transition(Automate & automate, Symbole * s) = 0 ;
		
	protected :
		string name;
};

#endif //ETAT.HPP
