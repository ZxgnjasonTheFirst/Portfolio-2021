using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Destroy_obj : MonoBehaviour
{

    public void OnTriggerEnter(Collider other)
    {
        if(other.tag == "shell")
        {
            GameObject.Destroy(this.gameObject);
        }
    }
}
