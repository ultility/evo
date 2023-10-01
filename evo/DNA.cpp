#include "DNA.h"
#include <bitset>

/*DNA::DNA(int length)
{
	std::mt19937 rng(time(0));
	std::uniform_int_distribution<int> gen(0, Bases::base_amount - 1);
	for (int i = 0; i < length; i++)
	{
		if (strand.Sequence.length() <= i / 4)
		{
			strand.Sequence += (char)0;
		}
		int random = gen(rng);
		random <<= ((i % 4) * 2);
		strand.Sequence[i / 4] |= random;
	}
	strand.length = length;
}

DNA::DNA(std::string sequence, int length)
{
	strand.Sequence = sequence;
	strand.length = length;
}

void DNA::MutateSequence(Sequence& strand)
{
	std::string mutation;
	int length = 0;
	std::mt19937 rng(time(0));
	std::uniform_int_distribution<int> mutation_type_gen(0, Mutations::mutation_amount - 1);
	std::uniform_real_distribution<float> mutation_gen(0, 1);
	std::uniform_int_distribution<int> base_gen(0, Bases::base_amount - 1);
	for (int i = 0; i < strand.length; i++)
	{
		char base = (strand.Sequence[i / 4] >> ((i % 4) * 2)) & 0b11;
		if (mutation_gen(rng) < DNA::MUTATION_CHANCE / 100)
		{
			switch (mutation_type_gen(rng))
			{
			case Mutations::duplication:
			{
				if (mutation.length() <= (length + 1) / 4)
				{
					mutation += (char)0;
				}
				mutation[length / 4] |= base << ((length % 4) * 2);
				mutation[(length + 1) / 4] |= base << (((length + 1) % 4) * 2);
				length += 2;
				std::cout << "duplication at " << length << std::endl;
				break;
			}
			case Mutations::insertion:
			{
				if (mutation.length() <= (length + 1) / 4)
				{
					mutation += (char)0;
				}
				int random = base_gen(rng);
				random <<= ((length % 4) * 2);
				mutation[length / 4] |= random;
				mutation[(length + 1) / 4] |= base << (((length + 1) % 4) * 2);
				length += 2;
				std::cout << "insertion at " << length << std::endl;
				break;
			}
			case Mutations::deletion:
			{
				std::cout << "deletion at " << length << std::endl;
				break;
			}

			}
		}
		else {
			if (mutation.length() <= length / 4)
			{
				mutation += (char)0;
			}
			mutation[i / 4] |= base << ((length % 4) * 2);
			length += 1;
		}
	}
	strand.length = length;
	strand.Sequence = mutation;
}

int DNA::GetLength()
{
	return strand.length;
}

std::string DNA::GetSequence()
{
	return strand.Sequence;
}

std::string DNA::ToString()
{
	std::string translated = "";
	for (int i = 0; i < strand.length; i++)
	{
		char base = (strand.Sequence[i / 4] >> ((i % 4) * 2)) & 0b11;
		switch (base)
		{
		case Bases::A:
			translated += "A";
			break;
		case Bases::T:
			translated += "T";
			break;
		case Bases::C:
			translated += "C";
			break;
		case Bases::G:
			translated += "G";
			break;
		}
	}
	return translated;
}*/

DNA::DNA(int length)
{
	strand.Sequence = "";
	strand.length = length;
	static std::mt19937 rng(time(0));
	std::uniform_int_distribution<int> gen(0, Bases::base_amount - 1);
	for (int i = 0; i < length; i++)
	{
		switch (gen(rng))
		{
		case Bases::A:
			strand.Sequence += 'A';
			break;
		case Bases::T:
			strand.Sequence += 'T';
			break;
		case Bases::G:
			strand.Sequence += 'G';
			break;
		case Bases::C:
			strand.Sequence += 'C';
			break;
		}
	}
}

DNA::DNA(std::string sequence, int length)
{
	for (char c : sequence)
	{
		if (c != 'A' && c != 'T' && c != 'G' && c != 'C')
		{
			std::cout << "sequence not possible";
			strand.Sequence = "";
			strand.length = 0;
			break;
		}
	}
	strand.Sequence = sequence;
	strand.length = length;
}

int DNA::GetLength()
{
	return strand.Sequence.length();
}

std::string DNA::GetSequence()
{
	return strand.Sequence;
}

void DNA::MutateSequence(Sequence& strand)
{
	static std::mt19937 rng(time(0));
	std::uniform_int_distribution mutation_type_gen(0, Mutations::mutation_amount - 1);
	std::uniform_int_distribution base_gen(0, Bases::base_amount - 1);
	std::uniform_real_distribution mutation_gen(0.0, 1.0);
	for (int i = 0; i < strand.Sequence.length();)
	{
		float mutation = mutation_gen(rng);
		if (mutation < MUTATION_CHANCE / 100)
		{
			switch (mutation_type_gen(rng))
			{
			case Mutations::deletion:
				std::cout << "deletion of: " << strand.Sequence[i] << " at " << i + 1 << std::endl;
				strand.Sequence = strand.Sequence.substr(0, i) + strand.Sequence.substr(i+1);
				break;
			case Mutations::duplication:
				strand.Sequence = strand.Sequence.substr(0, i) + strand.Sequence[i] + strand.Sequence.substr(i+1);
				std::cout << "dupe of: " << strand.Sequence[i] << " at " << i + 1 << std::endl;
				i += 2;
				break;
			case Mutations::insertion:
				int random = base_gen(rng);
				char base = (random == Bases::A) ? 'A' : (random == Bases::T) ? 'T' : (random == Bases::C) ? 'C' : 'G';
				strand.Sequence = strand.Sequence.substr(0, i) + base + strand.Sequence.substr(i+1);
				std::cout << "insertion of " << base <<  " at " << i + 1 << std::endl;
				i += 2;
			}
		}
		else
		{
			i++;
		}
	}
}

