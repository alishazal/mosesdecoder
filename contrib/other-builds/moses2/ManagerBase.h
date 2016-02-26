/*
 * Manager.h
 *
 *  Created on: 23 Oct 2015
 *      Author: hieu
 */

#pragma once

#include <queue>
#include <cstddef>
#include <string>
#include <deque>
#include "InputPaths.h"
#include "Phrase.h"
#include "MemPool.h"
#include "Recycler.h"
#include "EstimatedScores.h"
#include "legacy/Bitmaps.h"

namespace Moses2
{

class System;
class TranslationTask;
class PhraseImpl;
class SearchNormal;
class Search;
class Hypothesis;
class Sentence;
class OutputCollector;

class ManagerBase
{
public:
	const System &system;
	const TranslationTask &task;

	ManagerBase(System &sys, const TranslationTask &task, const std::string &inputStr, long translationId);
	virtual ~ManagerBase();
	virtual void Decode() = 0;

	MemPool &GetPool() const
	{ return *m_pool; }

	MemPool &GetSystemPool() const
	{ return *m_systemPool; }

	const Sentence &GetInput() const
	{ return *m_input; }

protected:
    std::string m_inputStr;
    long m_translationId;
	Sentence *m_input;

	mutable MemPool *m_pool, *m_systemPool;

	void InitPools();
	void ParseInput();

};


}
