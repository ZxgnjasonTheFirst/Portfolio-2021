using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Team_Manager : MonoBehaviour
{
    public static Team_Manager TM;

    // private Slider tankSlider;

    // private Toggle activeTeamToggle;

    private Tank_Manager[] TankManagers;

    public bool isActiveTeam = true;

    [Range(1, 4)]
    public int howManyTanks = 1;

    private Color m_playerColor;
    private int m_playerNumber = 0; 
    private int m_teamNumber = 0;
    
    public Color playerColor 
    { 
        get{ return m_playerColor; }
        set{ m_playerColor = value; } 
    }

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

    Vector3[] spawnPoints;

    [HideInInspector]
    public GameObject tankPrefab;

    public void setup()
    {   
        // // // Debug.Log("This is my team number: " + teamNumber);
        // int realTeamNumber = teamNumber + 1;
        // string SliderName = "Team " + realTeamNumber + " Slider";
        // Debug.Log(SliderName);
        // GameObject TankSliderObj = GameObject.Find(SliderName);

        // // tankSlider = TankSliderObj.GetComponent<Slider>();

        // activeTeamToggle = TankSliderObj.GetComponentInChildren<Toggle>();

        // activeTeamToggle.isOn = isActiveTeam;

        // tankSlider.value = (float)howManyTanks;

        TankManagers = GetComponentsInChildren<Tank_Manager>();
        spawnPoints = new Vector3[TankManagers.Length];
        for (int i = 0; i < TankManagers.Length; i++)
        {
            spawnPoints[i] = TankManagers[i].transform.position;
            TankManagers[i].teamNumber = teamNumber;
            TankManagers[i].playerColor = playerColor;
            TankManagers[i].playerNumber = i;  
        }
        spawnTeam();
    }

    public void spawnTeam()
    {
        if (isActiveTeam)
        {
            for (int i = 0; i < howManyTanks; i++)
            {
                spawnTank(i);
            }
        }
    }


    void spawnTank(int playerIndex)
    {
        Debug.Log("Spawning a tank with spawnTank.");
        TankManagers[playerIndex].setTank(Instantiate(tankPrefab, spawnPoints[playerIndex], Quaternion.identity));

    }

    public void tankKilled(int playerIndex)
    {
        TankManagers[playerIndex].tankKilled();
    }

    public void resetAllTanks()
    {
        for (int i = 0; i < TankManagers.Length; i++)
        {
            tankKilled(i);
        }
    }

    public void HowManyTanks(float newNumberOfTanks)
    {
        howManyTanks = (int)newNumberOfTanks;
    }

    public void ToggleActiveTeam(bool toggle)
    {
        isActiveTeam = toggle;
    }
}
