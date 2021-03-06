#pragma once
#include <optional>

#include "snd_local.h"

class VOX final
{
private:
  alure::Array<alure::String, CVOXWORDMAX> rgpparseword{};  // array parsed words
  alure::String voxperiod = "_period";                      // vocal pause
  alure::String voxcomma = "_comma";                        // vocal pause
  voxword_t voxwordDefault;

  // Voice file lookup
  std::optional<alure::String> LookupString(char *pszin, int *psentencenum);
  alure::String GetDirectory(alure::String& szpath, alure::String& psz);
  void ParseString(const alure::String& psz);
  bool ParseWordParams(alure::String& psz, voxword_t *pvoxword, int fFirst);
  int IFindEmptySentence(void);

  // Mouth movement
  void ForceInitMouth(int entnum);
  void ForceCloseMouth(int entnum);

public:
  alure::Array<alure::Array<voxword_t, CVOXWORDMAX>, CVOXSENTENCEMAX> rgrgvoxword;

  VOX();
  ~VOX();

  void TrimStartEndTimes(aud_channel_t *ch, aud_sfxcache_t *sc);
  void SetChanVolPitch(aud_channel_t *ch, float *fvol, float *fpitch);
  void ReadSentenceFile(void);
  aud_sfxcache_t *LoadSound(aud_channel_t *pchan, char *pszin);
  void MakeSingleWordSentence(aud_channel_t *ch, int pitch);
  void InitMouth(int entnum, int entchannel);
  void CloseMouth(aud_channel_t *ch);
  void MoveMouth(aud_channel_t *ch, aud_sfxcache_t *sc);
};