/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.7
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package democmds.core;

public class Chars {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected Chars(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(Chars obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        democmdsJNI.delete_Chars(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public Chars(int n) {
    this(democmdsJNI.new_Chars__SWIG_0(n), true);
  }

  public Chars() {
    this(democmdsJNI.new_Chars__SWIG_1(), true);
  }

  public void setSize(int n) {
    democmdsJNI.Chars_setSize(swigCPtr, this, n);
  }

  public Chars(char v1, char v2) {
    this(democmdsJNI.new_Chars__SWIG_2(v1, v2), true);
  }

  public Chars(char v1, char v2, char v3, char v4) {
    this(democmdsJNI.new_Chars__SWIG_3(v1, v2, v3, v4), true);
  }

  public int count() {
    return democmdsJNI.Chars_count(swigCPtr, this);
  }

  public char get(int index) {
    return democmdsJNI.Chars_get(swigCPtr, this, index);
  }

  public void set(int index, char value) {
    democmdsJNI.Chars_set__SWIG_0(swigCPtr, this, index, value);
  }

  public void set(int index, char v1, char v2) {
    democmdsJNI.Chars_set__SWIG_1(swigCPtr, this, index, v1, v2);
  }

}
