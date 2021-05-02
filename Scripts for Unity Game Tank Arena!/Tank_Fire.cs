using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Tank_Fire : MonoBehaviour
{

    public GameObject shell;
    private Transform firePos;
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
    public float FirePower = 8;
    public float FirePowerRange  =7;
    private Color playerColor;

    KeyCode fireKey;

    //added cooldown, because spamming started causing lag for me, especially with the particle effect.
    [SerializeField]
    private float CD = 0.1f;
    private float timeReady = 0;

    // Start is called before the first frame update
    void Start()
    {
        firePos = transform.Find("FirePoint");
    }

    // Update is called once per frame
    void Update()
    {
        Fire();
    }

    public void Fire(string AIInput = "") 
    {
        if(AIInput == "FIRE")
        {
            if (Time.time >= timeReady) // cooldown system
            {
                timeReady = Time.time + CD; //adds delay
                GameObject s = Instantiate(shell, firePos.position, firePos.rotation);
                s.GetComponent<Rigidbody>().velocity = s.transform.forward * (Random.Range(-FirePowerRange, FirePowerRange)+FirePower);
                s.GetComponent<Shell>().playerNumber = this.playerNumber;
                s.GetComponent<Shell>().teamNumber = this.teamNumber;                
                s.GetComponent<Renderer>().material.SetColor("_Color", playerColor);
            }
        }
    }


    public void setup(KeyCode whichKey, int teamNumberInput, int playerNumberInput, Color playerColor)
    {
        fireKey = whichKey;
        teamNumber = teamNumberInput;
        playerNumber = playerNumberInput;
        this.playerColor = playerColor;
        timeReady = Time.time + 1f;     // Forbid firing until 1 second after spawning. It prevents shell from escaping the arena while falling.
    }

}
