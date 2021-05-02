using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Shell : MonoBehaviour
{
    public GameObject exp;
    private int m_playerNumber = 0; 
    private int m_teamNumber = 0;

    public int teamNumber 
    { 
        get { return m_teamNumber; } 
        set { m_teamNumber = value; }  
    }

    public int playerNumber 
    { 
        get { return m_playerNumber; } 
        set { m_playerNumber = value; } 
    }
    // Start is called before the first frame update

    private void Start()
    {
        int randomInt = Random.Range(0, 7);
        GetComponent<MeshFilter>().mesh = Resources.Load<Mesh>("Models/" + randomInt);
    }
    public void OnTriggerEnter(Collider other)
    {
        if (other.tag == "shell") return;   //shells were interacting with each other, so I got rid of it.


        Debug.Log(playerNumber + "'s shell hit " + other.name);
        //checks if the collided object has TankManager script, and that it is owned by other player
        Tank_Fire other_TF = other.GetComponent<Tank_Fire>();
        if(other_TF != null)
        {
            if (other_TF.teamNumber == this.teamNumber)//do not collide with your own bullet
                return;
            Debug.Log("Target Hit!");
            GameManager.GM.TeamManagers[other_TF.teamNumber].tankKilled(other_TF.playerNumber);
        }
        GameObject.Instantiate(exp, transform.position, transform.rotation);
        GameObject.Destroy(this.gameObject);
    }
}
