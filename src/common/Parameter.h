//-------------------------------------------------------------------------------------------------------
//	Copyright 2005 Claes Johanson & Vember Audio
//-------------------------------------------------------------------------------------------------------
#pragma once
#include "globals.h"

union pdata
{
   int i;
   bool b;
   float f;
};

enum valtypes
{
   vt_int = 0,
   vt_bool,
   vt_float,
};

enum ctrltypes
{
   ct_none,
   ct_percent,
   ct_percent_bidirectional,
   ct_pitch_octave,
   ct_pitch_semi7bp,
   ct_pitch,
   ct_fmratio,
   ct_fmratio_int,
   ct_pbdepth,
   ct_syncpitch,
   ct_amplitude,
   ct_reverbshape,
   ct_decibel,
   ct_decibel_narrow,
   ct_decibel_extra_narrow,
   ct_decibel_attenuation,
   ct_decibel_attenuation_large,
   ct_decibel_fmdepth,
   ct_freq_audible,
   ct_freq_mod,
   ct_freq_hpf,
   ct_freq_shift,
   ct_bandwidth,
   ct_envtime,
   ct_envtime_lfodecay,
   ct_envshape,
   ct_envmode,
   ct_delaymodtime,
   ct_reverbtime,
   ct_portatime,
   ct_lforate,
   ct_lfoshape,
   ct_lfotrigmode,
   ct_detuning,
   ct_osctype,
   ct_fxtype,
   ct_fxbypass,
   ct_fbconfig,
   ct_fmconfig,
   ct_filtertype,
   ct_filtersubtype,
   ct_wstype,
   ct_wt2window,
   ct_osccount,
   ct_osccountWT,
   ct_oscspread,
   ct_scenemode,
   ct_scenesel,
   ct_polymode,
   ct_polylimit,
   ct_midikey,
   ct_bool,
   ct_bool_relative_switch,
   ct_bool_link_switch,
   ct_bool_keytrack,
   ct_bool_retrigger,
   ct_bool_unipolar,
   ct_bool_mute,
   ct_bool_solo,
   ct_oscroute,
   ct_stereowidth,
   ct_bool_fm,
   ct_character,
   num_ctrltypes,
};

enum ctrl_style
{
   cs_off = 0,
};

class Parameter
{
public:
   Parameter();
   Parameter* assign(int id,
                     int pid,
                     const char* name,
                     const char* dispname,
                     int ctrltype,
                     int posx,
                     int posy,
                     int scene = 0,
                     int ctrlgroup = 0,
                     int ctrlgroup_entry = 0,
                     bool modulateable = true,
                     int ctrlstyle = cs_off);
   bool can_temposync();
   bool can_extend_range();
   bool can_be_absolute();
   void clear_flags();
   void set_type(int ctrltype);
   void morph(Parameter* a, Parameter* b, float x);
   //	void morph(parameter *b, float x);
   pdata morph(Parameter* b, float x);
   const char* get_name();
   const char* get_full_name();
   void set_name(const char* n); // never change name_storage as it is used for storage/recall
   const char* get_internal_name();
   const char* get_storage_name();
   const wchar_t* getUnit() const;
   void get_display(char* txt, bool external = false, float ef = 0.f);
   char* get_storage_value(char*);
   void set_storage_value(int i);
   void set_storage_value(float f);
   float get_extended(float f);
   float get_value_f01();
   float normalized_to_value(float value);
   float value_to_normalized(float value);
   float get_default_value_f01();
   void set_value_f01(float v, bool force_integer = false);
   float
   get_modulation_f01(float mod);     // used by the gui to get the position of the modulated handle
   float set_modulation_f01(float v); // used by the gui to set the modulation to match the position
                                      // of the modulated handle
   void bound_value(bool force_integer = false);
   pdata val, val_default, val_min, val_max;
   int id;
   char name[namechars], dispname[namechars], name_storage[namechars], fullname[namechars];
   bool modulateable;
   int valtype;
   int scene; // 0 = patch, 1 = scene A, 2 = scene B
   int ctrltype, posx, posy, posy_offset;
   int ctrlgroup, ctrlgroup_entry, ctrlstyle;
   int midictrl;
   int param_id_in_scene;
   bool affect_other_parameters;
   float moverate;
   bool per_voice_processing;
   bool temposync, extend_range, absolute;
};