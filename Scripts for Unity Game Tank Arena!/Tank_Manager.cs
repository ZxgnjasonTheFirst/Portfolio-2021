using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Tank_Manager : MonoBehaviour
{
    [SerializeField]
    private KeyCode fireKey;
    // [SerializeField]
    // private KeyCode[] WASD = new KeyCode[4];
    private Color m_playerColor; 
    
    public Color playerColor 
    { 
        get{ return m_playerColor; }
        set{ m_playerColor = value; } 
    }

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

    public GameObject tankInstance;

    private GameObject[] otherTankInstances;



    /// <summary>
    /// // takes the instantiated tank from the GameManager and save that on tankInstance variable
    /// </summary>
    /// <param name="spawnedTank"></param>
    public void setTank(GameObject spawnedTank) 
    {
        tankInstance = spawnedTank;
        Debug.Log("Spawned a tank");
        tankInstance.GetComponent<Tank_Fire>().setup(fireKey,teamNumber, playerNumber, playerColor);
        tankInstance.GetComponent<Tank_Move>().teamNumber = teamNumber;
        Transform tankRendererObject = tankInstance.transform.GetChild(0);
        for (int i = 0; i < 4; i++)
        {
            tankRendererObject.GetChild(i).GetComponent<Renderer>().material.SetColor("_Color", playerColor);
        }
    }

    public void tankKilled()
    {
        Destroy(tankInstance);
    }



}
