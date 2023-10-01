#pragma once

#include <random>
#include <string>
#include <iostream>

enum Mutations
{
	duplication = 0,
	insertion,
	deletion,
	mutation_amount
};

enum Bases
{
	A = 0,
	T,
	C,
	G,
	base_amount
};

struct Sequence
{
	std::string Sequence;
	int length = 0;
};

struct Codon
{
	char codon[3];
};

class DNA
{
public:
	inline static const float MUTATION_CHANCE = 1;// mutation chance in percent
	static void MutateSequence(Sequence& strand);
	DNA(int length);
	DNA(std::string sequence, int length);
	std::string ToString();
	std::string GetSequence();
	int GetLength();
	DNA Divide();
private:
	Sequence strand;
};