using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ShowValueScript : MonoBehaviour
{
    public Text TankQuantity;
    private Slider thisSlider;

    [SerializeField]
    private Toggle thisToggle;
    [SerializeField]
    private Team_Manager ThisTeamManager;

    void Start()
    {
        Debug.Log(gameObject.name);
        TankQuantity = GetComponent<Text>();
        thisSlider = GetComponentInParent<Slider>();
        thisToggle.isOn = ThisTeamManager.isActiveTeam;
        TankQuantity.text = ThisTeamManager.howManyTanks.ToString();
    }

    void Update()
    {
        thisSlider.value = ThisTeamManager.howManyTanks;
    }

    public void textUpdate(float newNumber)
    {
        TankQuantity.text = newNumber.ToString();
    }
}
