//#line 2 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"
// *********************************************************
// 
// File autogenerated for the twist_controller package 
// by the dynamic_reconfigure package.
// Please do not edit.
// 
// ********************************************************/

#ifndef __twist_controller__PIDPARAMSCONFIG_H__
#define __twist_controller__PIDPARAMSCONFIG_H__

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace twist_controller
{
  class PIDParamsConfigStatics;
  
  class PIDParamsConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l, 
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }
      
      virtual void clamp(PIDParamsConfig &config, const PIDParamsConfig &max, const PIDParamsConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const PIDParamsConfig &config1, const PIDParamsConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, PIDParamsConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const PIDParamsConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, PIDParamsConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const PIDParamsConfig &config) const = 0;
      virtual void getValue(const PIDParamsConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;
    
    template <class T>
    class ParamDescription : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string a_name, std::string a_type, uint32_t a_level, 
          std::string a_description, std::string a_edit_method, T PIDParamsConfig::* a_f) :
        AbstractParamDescription(a_name, a_type, a_level, a_description, a_edit_method),
        field(a_f)
      {}

      T (PIDParamsConfig::* field);

      virtual void clamp(PIDParamsConfig &config, const PIDParamsConfig &max, const PIDParamsConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;
        
        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const PIDParamsConfig &config1, const PIDParamsConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, PIDParamsConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const PIDParamsConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, PIDParamsConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const PIDParamsConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const PIDParamsConfig &config, boost::any &val) const
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, PIDParamsConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); ++i)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    template<class T, class PT>
    class GroupDescription : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string a_name, std::string a_type, int a_parent, int a_id, bool a_s, T PT::* a_f) : AbstractGroupDescription(a_name, a_type, a_parent, a_id, a_s), field(a_f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }

      virtual void updateParams(boost::any &cfg, PIDParamsConfig &top) const
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T (PT::* field);
      std::vector<PIDParamsConfig::AbstractGroupDescriptionConstPtr> groups;
    };
    
class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(PIDParamsConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);


      }
    }

    

    bool state;
    std::string name;

    class STEER
{
  public:
    STEER()
    {
      state = true;
      name = "Steer";
    }

    void setParams(PIDParamsConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("Steer_P"==(*_i)->name){Steer_P = boost::any_cast<double>(val);}
        if("Steer_I"==(*_i)->name){Steer_I = boost::any_cast<double>(val);}
        if("Steer_D"==(*_i)->name){Steer_D = boost::any_cast<double>(val);}
      }
    }

    double Steer_P;
double Steer_I;
double Steer_D;

    bool state;
    std::string name;

    
}steer;

class THROTTLE
{
  public:
    THROTTLE()
    {
      state = true;
      name = "Throttle";
    }

    void setParams(PIDParamsConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("Throttle_P"==(*_i)->name){Throttle_P = boost::any_cast<double>(val);}
        if("Throttle_I"==(*_i)->name){Throttle_I = boost::any_cast<double>(val);}
        if("Throttle_D"==(*_i)->name){Throttle_D = boost::any_cast<double>(val);}
      }
    }

    double Throttle_P;
double Throttle_I;
double Throttle_D;

    bool state;
    std::string name;

    
}throttle;

}groups;



//#line 9 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      double Steer_P;
//#line 10 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      double Steer_I;
//#line 11 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      double Steer_D;
//#line 14 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      double Throttle_P;
//#line 15 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      double Throttle_I;
//#line 16 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      double Throttle_D;
//#line 218 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("PIDParamsConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }
    
    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }
    
    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const PIDParamsConfig &__max__ = __getMax__();
      const PIDParamsConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const PIDParamsConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }
    
    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const PIDParamsConfig &__getDefault__();
    static const PIDParamsConfig &__getMax__();
    static const PIDParamsConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();
    
  private:
    static const PIDParamsConfigStatics *__get_statics__();
  };
  
  template <> // Max and min are ignored for strings.
  inline void PIDParamsConfig::ParamDescription<std::string>::clamp(PIDParamsConfig &config, const PIDParamsConfig &max, const PIDParamsConfig &min) const
  {
    (void) config;
    (void) min;
    (void) max;
    return;
  }

  class PIDParamsConfigStatics
  {
    friend class PIDParamsConfig;
    
    PIDParamsConfigStatics()
    {
PIDParamsConfig::GroupDescription<PIDParamsConfig::DEFAULT, PIDParamsConfig> Default("Default", "", 0, 0, true, &PIDParamsConfig::groups);
PIDParamsConfig::GroupDescription<PIDParamsConfig::DEFAULT::STEER, PIDParamsConfig::DEFAULT> Steer("Steer", "", 0, 1, true, &PIDParamsConfig::DEFAULT::steer);
//#line 9 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      __min__.Steer_P = 0.0;
//#line 9 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      __max__.Steer_P = 1.0;
//#line 9 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      __default__.Steer_P = 0.58;
//#line 9 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      Steer.abstract_parameters.push_back(PIDParamsConfig::AbstractParamDescriptionConstPtr(new PIDParamsConfig::ParamDescription<double>("Steer_P", "double", 0, "P value for Steer PID controller", "", &PIDParamsConfig::Steer_P)));
//#line 9 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      __param_descriptions__.push_back(PIDParamsConfig::AbstractParamDescriptionConstPtr(new PIDParamsConfig::ParamDescription<double>("Steer_P", "double", 0, "P value for Steer PID controller", "", &PIDParamsConfig::Steer_P)));
//#line 10 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      __min__.Steer_I = 0.0;
//#line 10 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      __max__.Steer_I = 1.0;
//#line 10 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      __default__.Steer_I = 0.0108;
//#line 10 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      Steer.abstract_parameters.push_back(PIDParamsConfig::AbstractParamDescriptionConstPtr(new PIDParamsConfig::ParamDescription<double>("Steer_I", "double", 0, "I value for Steer PID controller", "", &PIDParamsConfig::Steer_I)));
//#line 10 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      __param_descriptions__.push_back(PIDParamsConfig::AbstractParamDescriptionConstPtr(new PIDParamsConfig::ParamDescription<double>("Steer_I", "double", 0, "I value for Steer PID controller", "", &PIDParamsConfig::Steer_I)));
//#line 11 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      __min__.Steer_D = 0.0;
//#line 11 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      __max__.Steer_D = 1.0;
//#line 11 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      __default__.Steer_D = 0.001;
//#line 11 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      Steer.abstract_parameters.push_back(PIDParamsConfig::AbstractParamDescriptionConstPtr(new PIDParamsConfig::ParamDescription<double>("Steer_D", "double", 0, "D value for Steer PID controller", "", &PIDParamsConfig::Steer_D)));
//#line 11 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      __param_descriptions__.push_back(PIDParamsConfig::AbstractParamDescriptionConstPtr(new PIDParamsConfig::ParamDescription<double>("Steer_D", "double", 0, "D value for Steer PID controller", "", &PIDParamsConfig::Steer_D)));
//#line 123 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Steer.convertParams();
//#line 123 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.groups.push_back(PIDParamsConfig::AbstractGroupDescriptionConstPtr(new PIDParamsConfig::GroupDescription<PIDParamsConfig::DEFAULT::STEER, PIDParamsConfig::DEFAULT>(Steer)));
//#line 123 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(PIDParamsConfig::AbstractGroupDescriptionConstPtr(new PIDParamsConfig::GroupDescription<PIDParamsConfig::DEFAULT::STEER, PIDParamsConfig::DEFAULT>(Steer)));
PIDParamsConfig::GroupDescription<PIDParamsConfig::DEFAULT::THROTTLE, PIDParamsConfig::DEFAULT> Throttle("Throttle", "", 0, 2, true, &PIDParamsConfig::DEFAULT::throttle);
//#line 14 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      __min__.Throttle_P = 0.0;
//#line 14 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      __max__.Throttle_P = 1.0;
//#line 14 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      __default__.Throttle_P = 0.6;
//#line 14 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      Throttle.abstract_parameters.push_back(PIDParamsConfig::AbstractParamDescriptionConstPtr(new PIDParamsConfig::ParamDescription<double>("Throttle_P", "double", 1, "P value for Throttle PID controller", "", &PIDParamsConfig::Throttle_P)));
//#line 14 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      __param_descriptions__.push_back(PIDParamsConfig::AbstractParamDescriptionConstPtr(new PIDParamsConfig::ParamDescription<double>("Throttle_P", "double", 1, "P value for Throttle PID controller", "", &PIDParamsConfig::Throttle_P)));
//#line 15 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      __min__.Throttle_I = 0.0;
//#line 15 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      __max__.Throttle_I = 1.0;
//#line 15 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      __default__.Throttle_I = 0.01;
//#line 15 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      Throttle.abstract_parameters.push_back(PIDParamsConfig::AbstractParamDescriptionConstPtr(new PIDParamsConfig::ParamDescription<double>("Throttle_I", "double", 1, "I value for Throttle PID controller", "", &PIDParamsConfig::Throttle_I)));
//#line 15 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      __param_descriptions__.push_back(PIDParamsConfig::AbstractParamDescriptionConstPtr(new PIDParamsConfig::ParamDescription<double>("Throttle_I", "double", 1, "I value for Throttle PID controller", "", &PIDParamsConfig::Throttle_I)));
//#line 16 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      __min__.Throttle_D = 0.0;
//#line 16 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      __max__.Throttle_D = 1.0;
//#line 16 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      __default__.Throttle_D = 0.0;
//#line 16 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      Throttle.abstract_parameters.push_back(PIDParamsConfig::AbstractParamDescriptionConstPtr(new PIDParamsConfig::ParamDescription<double>("Throttle_D", "double", 1, "D value for Throttle PID controller", "", &PIDParamsConfig::Throttle_D)));
//#line 16 "/home/student/Documents/Final-System-Integrated/ros/src/twist_controller/cfg/PIDParams.cfg"
      __param_descriptions__.push_back(PIDParamsConfig::AbstractParamDescriptionConstPtr(new PIDParamsConfig::ParamDescription<double>("Throttle_D", "double", 1, "D value for Throttle PID controller", "", &PIDParamsConfig::Throttle_D)));
//#line 123 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Throttle.convertParams();
//#line 123 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.groups.push_back(PIDParamsConfig::AbstractGroupDescriptionConstPtr(new PIDParamsConfig::GroupDescription<PIDParamsConfig::DEFAULT::THROTTLE, PIDParamsConfig::DEFAULT>(Throttle)));
//#line 123 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(PIDParamsConfig::AbstractGroupDescriptionConstPtr(new PIDParamsConfig::GroupDescription<PIDParamsConfig::DEFAULT::THROTTLE, PIDParamsConfig::DEFAULT>(Throttle)));
//#line 246 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 246 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(PIDParamsConfig::AbstractGroupDescriptionConstPtr(new PIDParamsConfig::GroupDescription<PIDParamsConfig::DEFAULT, PIDParamsConfig>(Default)));
//#line 356 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

      for (std::vector<PIDParamsConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__); 
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__); 
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__); 
    }
    std::vector<PIDParamsConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<PIDParamsConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    PIDParamsConfig __max__;
    PIDParamsConfig __min__;
    PIDParamsConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const PIDParamsConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static PIDParamsConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &PIDParamsConfig::__getDescriptionMessage__() 
  {
    return __get_statics__()->__description_message__;
  }

  inline const PIDParamsConfig &PIDParamsConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }
  
  inline const PIDParamsConfig &PIDParamsConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }
  
  inline const PIDParamsConfig &PIDParamsConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }
  
  inline const std::vector<PIDParamsConfig::AbstractParamDescriptionConstPtr> &PIDParamsConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<PIDParamsConfig::AbstractGroupDescriptionConstPtr> &PIDParamsConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const PIDParamsConfigStatics *PIDParamsConfig::__get_statics__()
  {
    const static PIDParamsConfigStatics *statics;
  
    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = PIDParamsConfigStatics::get_instance();
    
    return statics;
  }


}

#endif // __PIDPARAMSRECONFIGURATOR_H__