/**********************************************************************

  Audacity: A Digital Audio Editor

  StatefulEffect.h

  Dominic Mazzoni
  Vaughan Johnson

  Paul Licameli split from Effect.h

**********************************************************************/

#ifndef __AUDACITY_STATEFUL_EFFECT__
#define __AUDACITY_STATEFUL_EFFECT__

#include "StatefulEffectBase.h"
#include "Effect.h"

//! Subclass of Effect, to be eliminated after all of its subclasses
//! are rewritten to be stateless
class StatefulEffect
   : public StatefulEffectBase
   , public Effect
   , public BasicEffectUIServices
{
public:
   class AUDACITY_DLL_API Instance : public StatefulEffectBase::Instance {
   public:
      using StatefulEffectBase::Instance::Instance;
      bool Process(EffectSettings &settings) override;
      SampleCount GetLatency(
         const EffectSettings &settings, double sampleRate) const override;
      //! Default implementation fails (returns 0 always)
      size_t ProcessBlock(EffectSettings &settings,
         const float *const *inBlock, float *const *outBlock, size_t blockLen)
      override;
   };

   ~StatefulEffect() override;

   std::shared_ptr<EffectInstance> MakeInstance() const override;

   //! Allows PopulateOrExchange to return null
   std::unique_ptr<EffectEditor> PopulateUI(const EffectPlugin &plugin,
      ShuttleGui &S, EffectInstance &instance, EffectSettingsAccess &access,
      const EffectOutputs *pOutputs) const override;
};

#endif
